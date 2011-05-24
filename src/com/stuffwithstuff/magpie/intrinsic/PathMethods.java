package com.stuffwithstuff.magpie.intrinsic;

import java.io.File;

import com.stuffwithstuff.magpie.Def;
import com.stuffwithstuff.magpie.interpreter.Context;
import com.stuffwithstuff.magpie.interpreter.Obj;

public class PathMethods {
  @Def("(this is String) base")
  public static class Base implements Intrinsic {
    public Obj invoke(Context context, Obj left, Obj right) {
      return context.toObj(new File(left.asString()).getName());
    }
  }
}
