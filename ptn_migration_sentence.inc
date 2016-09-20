<?php


/**
 * @file
 * PTN custom booklet migration.
 */

class PtnSentenceMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import DataBase_converted.csv CSV-file');
    $columns = array(
      0 => array('SentenceID', t('Sentence ID')),
      1 => array('English', t('English')),
      2 => array('Section', t('Section')),
      3 => array('SectionID', t('SectionID')),
      4 => array('Unused1', t('Unused1')),
      5 => array('Audio', t('Audio')),
      6 => array('Picture', t('Picture')),
      7 => array('Ponca', t('Ponca')),
      8 => array('Unused2', t('Unused2')),
      9 => array('Folder', t('Folder')),
      10 => array('Unknown1', t('Unknown1')),
      11 => array('Unknown2', t('Unknown2')),
    );
    $this->source = new MigrateSourceCSV(
      DRUPAL_ROOT . '/' . drupal_get_path('module', 'ptn_migration') . '/DataBase_converted.csv',
      $columns,
      array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE
      )
    );
    $this->destination = new MigrateDestinationNode('sentence');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'SentenceID' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Mapped fields
    $this->addFieldMapping('uid')->defaultValue('1');
    $this->addFieldMapping('field_sentence', 'Ponca')->defaultValue('');
    $this->addFieldMapping('field_audio', 'Audio')->defaultValue('');
    $this->addFieldMapping('field_picture', 'Picture');
    $this->addFieldMapping('field_picture:source_dir')
      ->defaultValue(DRUPAL_ROOT . '/' . drupal_get_path('module', 'ptn_migration') . '/pictures');
    $this->addFieldMapping('field_image:alt', 'Picture');
    $this->addFieldMapping('field_translation', 'English')->defaultValue('');
    $this->addFieldMapping('og_group_ref', 'SectionID')->sourceMigration(array('PtnBooklet'));

  }

  public function prepare($entity, stdClass $row) {
    // Set og field_mode to 'admin' so we can save this group content despite not being a member of the group.
    if (!empty($entity->og_group_ref[LANGUAGE_NONE][0]['target_id'])) {
      $entity->og_group_ref[LANGUAGE_NONE][0]['field_mode'] = 'admin';
    }
  }

}
