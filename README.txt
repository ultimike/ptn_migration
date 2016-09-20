
Source pictures go in the /pictures directory of this module.

Source audio files go in the /audio directory of this module.

Modifications to the DataBase_converted.csv:
  *  Added SentenceID column.
  *  Added SectionID column.

Created a new booklet.csv file with the following columns:
  *  booklet_id - corresponds to the "SectionID" of DataBase_converted.csv
  *  booklet_name - corresponds to the "Section" of DataBase_converted.csv

This module contains two migrations, one for "booklets" and one for "sentences".

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
  *  field_audio (???)
  *  field_translation (text)
  *  field_picture (image)
  *  Automatic node title

## To run the migration

  *  Enable https://www.drupal.org/project/migrate
  *  Enable this module
  *  Via drush
    *  drush ms (displays status of migrations)
    *  drush mi PtnBooklet (runs booklet migration)
    *  drush mi PtnSentence (runs sentence migration)

