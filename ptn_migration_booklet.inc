<?php


/**
 * @file
 * PTN custom booklet migration.
 */

class PtnBookletMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import booklet.csv CSV-file');
    $columns = array(
      0 => array('booklet_id', t('Booklet ID')),
      1 => array('booklet_name', t('Booklet name')),
    );
    $this->source = new MigrateSourceCSV(
      DRUPAL_ROOT . '/' . drupal_get_path('module', 'ptn_migration') . '/booklet.csv',
      $columns,
      array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE
      )
    );
    $this->destination = new MigrateDestinationNode('booklet');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'booklet_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Mapped fields
    $this->addFieldMapping('field_translation', 'booklet_name')
      ->defaultValue('');
    $this->addFieldMapping('uid')->defaultValue('1');
  }
}
