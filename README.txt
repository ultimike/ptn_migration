
## Source Data
  *  Modifications to the DataBase_converted.csv:
    *  Added SentenceID column.
    *  Added SectionID column.
  *  Created a new booklet.csv file with the following columns:
    *  booklet_id - corresponds to the "SectionID" of DataBase_converted.csv
    *  booklet_name - corresponds to the "Section" of DataBase_converted.csv

##Site information architecture

Note: if the content type and field machine names in the actual site differ from what is
listed below, then the migration code must be modified to match.

*  Booklet ("booklet") content type
  *  OG group
  *  field_translation (text)
  *  Automatic node title

*  Sentence ("sentence") content type
  *  OG group content
  *  field_sentence (text)
  *  field_audio (file)
  *  field_translation (text)
  *  field_picture (image)
  *  Automatic node title

## To run the migration
  *  Enable https://www.drupal.org/project/migrate
  *  Enable this module
  *  Place source audio files in sites/all/modules/ptn_migration/audio/
  *  Place source pictures in sites/all/modules/ptn_migration/pictures/
  *  Via drush
    *  drush ms (displays status of migrations)
    *  drush mi PtnBooklet (runs booklet migration)
    *  drush mi PtnSentence (runs sentence migration)

## Module file descriptions
*  ptn_migration.info - standard custom module .info file, automatically includes two
migration classes.
*  ptn_migration.module - required by Drupal core, empty.
*  ptn_migration.migrate.inc - contains information for the Migrate API, declares our
migration classes.
*  ptn_migration_booklet.inc - migration class for nodes of type "booklet". Source data
from booklet.csv file.
*  ptn_migration_sentence.inc - migration class for nodes of type "sentence". Source data
from DataBase_converted.csv file.
  *  Maps audio files from sites/all/modules/ptn_migration/audio/
  *  Maps pictures from sites/all/modules/ptn_migration/pictures/
  *  Maps each "sentence" node to a "booklet" node via an Organic Groups reference field,
  using the booklet migration to ensure each sentence is assigned to the proper booklet.
  *  The prepare() method is necessary to complete the group assignment - otherwise the user
  running the migration would have to be a member of all booklet groups.

