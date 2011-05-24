package com.stuffwithstuff.magpie.app;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.net.URL;
import java.nio.charset.Charset;

import com.stuffwithstuff.magpie.MagpieHost;
import com.stuffwithstuff.magpie.SourceFile;

public class MagpieAppHost implements MagpieHost {
  @Override
  public SourceFile loadModule(String name) {
    try {
      String modulePath = name.replace('.', '/');
      
      // $CWD/foo/bar.mag
      File file = new File(modulePath + ".mag");
      if (file.exists()) {
        return new SourceFile(file.getPath(), readFile(file.getPath()));
      }
      
      // $CWD/foo/bar/_init.mag
      file = new File(modulePath + "/_init.mag");
      if (file.exists()) {
        return new SourceFile(file.getPath(), readFile(file.getPath()));
      }
      
      // $APPDIR/lib/foo/bar.mag
      File appDir = new File(getAppDirectory(), "lib");
      file = new File(appDir, modulePath + ".mag");
      if (file.exists()) {
        return new SourceFile(file.getPath(), readFile(file.getPath()));
      }
      
      // $APPDIR/lib/foo/bar/_init.mag
      file = new File(appDir, modulePath + "/_init.mag");
      if (file.exists()) {
        return new SourceFile(file.getPath(), readFile(file.getPath()));
      }

      throw new IOException("Couldn't find module " + name);
    } catch (IOException e) {
      e.printStackTrace();
      // TODO(bob): Handle error!
      return null;
    }
  }
  
  private static File getAppDirectory() {
    URL location = MagpieApp.class.getProtectionDomain().getCodeSource().getLocation();
    // Back up one directory to get out of "bin/".
    return new File(location.getFile()).getParentFile();
  }

  public static String readFile(String path) throws IOException {
    // If we're given a directory, look for _init.mag in it.
    File filePath = new File(path);
    if (filePath.isDirectory()) {
      path = new File(filePath, "_init.mag").getPath();
    }
    
    FileInputStream stream = new FileInputStream(path);

    try {
      InputStreamReader input = new InputStreamReader(
          stream, Charset.forName("UTF-8"));
      Reader reader = new BufferedReader(input);

      StringBuilder builder = new StringBuilder();
      char[] buffer = new char[8192];
      int read;

      while ((read = reader.read(buffer, 0, buffer.length)) > 0) {
        builder.append(buffer, 0, read);
      }

      return builder.toString();
    } finally {
      stream.close();
    }
  }}
