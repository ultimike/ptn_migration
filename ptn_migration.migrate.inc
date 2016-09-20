<?php

/**
 * Implement hook_migrate_api().
 *
 * API must be set to "2" for the 7.x-2.x branch of Migrate.
 */
function ptn_migration_migrate_api() {
  $common_arguments = array(

  );

  $api = array(
    'api' => 2,
    'groups' => array(
      'ptncustom' => array(
        'title' => t('PTN custom migrations'),
      ),
    ),
    'migrations' => array(
      'PtnBooklet' => $common_arguments + array(
        'class_name' => 'PtnBookletMigration',
        'destination_type' => 'booklet',
        'group_name' => 'ptncustom',
        'description' => 'Custom migration for booklets',
        'dependencies' => array(
        ),
      ),
      'PtnSentence' => $common_arguments + array(
        'class_name' => 'PtnSentenceMigration',
        'destination_type' => 'sentence',
        'group_name' => 'ptncustom',
        'description' => 'Custom migration for sentences',
        'dependencies' => array(
          'PtnBooklet',
        ),
      ),
    ),
  );
  return $api;
}
