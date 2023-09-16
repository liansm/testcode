<?php

function find_empty_files($dir) {
  $files = scandir($dir);
  foreach ($files as $file) {
    if ($file != '.' && $file != '..') {
      $path = $dir . DIRECTORY_SEPARATOR . $file;
      if (is_dir($path)) {
        find_empty_files($path);
      } else {
        if (filesize($path) == 0) {
          echo $path . PHP_EOL;
        }
      }
    }
  }
}


find_empty_files("/home/liansm");


?>
