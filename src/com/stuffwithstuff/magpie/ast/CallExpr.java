package com.stuffwithstuff.magpie.ast;

public class CallExpr extends Expr {
  public CallExpr(Expr target, Expr arg) {
    mTarget = target;
    mArg = arg;
  }
  
  @Override public String toString() {
    StringBuilder builder = new StringBuilder();
    builder.append(mTarget)
           .append("(");
    
    if (!(mArg instanceof UnitExpr)) builder.append(mArg);
    
    builder.append(")");
    return builder.toString();
  }
  
  private final Expr mTarget;
  private final Expr mArg;
}