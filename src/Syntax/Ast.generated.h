// Automatically generated by script/generate_ast.py.
// Do not hand-edit.

class AndExpr;
class AssignExpr;
class AsyncExpr;
class BoolExpr;
class BreakExpr;
class CallExpr;
class CatchExpr;
class CharacterExpr;
class DefExpr;
class DefClassExpr;
class DoExpr;
class FloatExpr;
class FnExpr;
class ForExpr;
class GetFieldExpr;
class IfExpr;
class ImportExpr;
class IntExpr;
class IsExpr;
class ListExpr;
class MatchExpr;
class NameExpr;
class NativeExpr;
class NotExpr;
class NothingExpr;
class OrExpr;
class RecordExpr;
class ReturnExpr;
class SequenceExpr;
class SetFieldExpr;
class StringExpr;
class ThrowExpr;
class VariableExpr;
class WhileExpr;
class CallLValue;
class NameLValue;
class RecordLValue;
class WildcardLValue;
class RecordPattern;
class TypePattern;
class ValuePattern;
class VariablePattern;

class ExprVisitor
{
public:
  virtual ~ExprVisitor() {}

  virtual void visit(AndExpr& node, int arg) = 0;
  virtual void visit(AssignExpr& node, int arg) = 0;
  virtual void visit(AsyncExpr& node, int arg) = 0;
  virtual void visit(BoolExpr& node, int arg) = 0;
  virtual void visit(BreakExpr& node, int arg) = 0;
  virtual void visit(CallExpr& node, int arg) = 0;
  virtual void visit(CatchExpr& node, int arg) = 0;
  virtual void visit(CharacterExpr& node, int arg) = 0;
  virtual void visit(DefExpr& node, int arg) = 0;
  virtual void visit(DefClassExpr& node, int arg) = 0;
  virtual void visit(DoExpr& node, int arg) = 0;
  virtual void visit(FloatExpr& node, int arg) = 0;
  virtual void visit(FnExpr& node, int arg) = 0;
  virtual void visit(ForExpr& node, int arg) = 0;
  virtual void visit(GetFieldExpr& node, int arg) = 0;
  virtual void visit(IfExpr& node, int arg) = 0;
  virtual void visit(ImportExpr& node, int arg) = 0;
  virtual void visit(IntExpr& node, int arg) = 0;
  virtual void visit(IsExpr& node, int arg) = 0;
  virtual void visit(ListExpr& node, int arg) = 0;
  virtual void visit(MatchExpr& node, int arg) = 0;
  virtual void visit(NameExpr& node, int arg) = 0;
  virtual void visit(NativeExpr& node, int arg) = 0;
  virtual void visit(NotExpr& node, int arg) = 0;
  virtual void visit(NothingExpr& node, int arg) = 0;
  virtual void visit(OrExpr& node, int arg) = 0;
  virtual void visit(RecordExpr& node, int arg) = 0;
  virtual void visit(ReturnExpr& node, int arg) = 0;
  virtual void visit(SequenceExpr& node, int arg) = 0;
  virtual void visit(SetFieldExpr& node, int arg) = 0;
  virtual void visit(StringExpr& node, int arg) = 0;
  virtual void visit(ThrowExpr& node, int arg) = 0;
  virtual void visit(VariableExpr& node, int arg) = 0;
  virtual void visit(WhileExpr& node, int arg) = 0;

protected:
  ExprVisitor() {}

private:
  NO_COPY(ExprVisitor);
};

class Expr : public Managed
{
public:
  Expr(gc<SourcePos> pos)
  : pos_(pos)
  {}

  virtual ~Expr() {}

  // The visitor pattern.
  virtual void accept(ExprVisitor& visitor, int arg) = 0;

  // Dynamic casts.
  virtual AndExpr* asAndExpr() { return NULL; }
  virtual AssignExpr* asAssignExpr() { return NULL; }
  virtual AsyncExpr* asAsyncExpr() { return NULL; }
  virtual BoolExpr* asBoolExpr() { return NULL; }
  virtual BreakExpr* asBreakExpr() { return NULL; }
  virtual CallExpr* asCallExpr() { return NULL; }
  virtual CatchExpr* asCatchExpr() { return NULL; }
  virtual CharacterExpr* asCharacterExpr() { return NULL; }
  virtual DefExpr* asDefExpr() { return NULL; }
  virtual DefClassExpr* asDefClassExpr() { return NULL; }
  virtual DoExpr* asDoExpr() { return NULL; }
  virtual FloatExpr* asFloatExpr() { return NULL; }
  virtual FnExpr* asFnExpr() { return NULL; }
  virtual ForExpr* asForExpr() { return NULL; }
  virtual GetFieldExpr* asGetFieldExpr() { return NULL; }
  virtual IfExpr* asIfExpr() { return NULL; }
  virtual ImportExpr* asImportExpr() { return NULL; }
  virtual IntExpr* asIntExpr() { return NULL; }
  virtual IsExpr* asIsExpr() { return NULL; }
  virtual ListExpr* asListExpr() { return NULL; }
  virtual MatchExpr* asMatchExpr() { return NULL; }
  virtual NameExpr* asNameExpr() { return NULL; }
  virtual NativeExpr* asNativeExpr() { return NULL; }
  virtual NotExpr* asNotExpr() { return NULL; }
  virtual NothingExpr* asNothingExpr() { return NULL; }
  virtual OrExpr* asOrExpr() { return NULL; }
  virtual RecordExpr* asRecordExpr() { return NULL; }
  virtual ReturnExpr* asReturnExpr() { return NULL; }
  virtual SequenceExpr* asSequenceExpr() { return NULL; }
  virtual SetFieldExpr* asSetFieldExpr() { return NULL; }
  virtual StringExpr* asStringExpr() { return NULL; }
  virtual ThrowExpr* asThrowExpr() { return NULL; }
  virtual VariableExpr* asVariableExpr() { return NULL; }
  virtual WhileExpr* asWhileExpr() { return NULL; }

  gc<SourcePos> pos() const { return pos_; }

private:
  gc<SourcePos> pos_;
};

class AndExpr : public Expr
{
public:
  AndExpr(gc<SourcePos> pos, gc<Expr> left, gc<Expr> right)
  : Expr(pos),
    left_(left),
    right_(right)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual AndExpr* asAndExpr() { return this; }

  gc<Expr> left() const { return left_; }
  gc<Expr> right() const { return right_; }

  virtual void reach()
  {
    left_.reach();
    right_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> left_;
  gc<Expr> right_;
  NO_COPY(AndExpr);
};

class AssignExpr : public Expr
{
public:
  AssignExpr(gc<SourcePos> pos, gc<LValue> lvalue, gc<Expr> value)
  : Expr(pos),
    lvalue_(lvalue),
    value_(value)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual AssignExpr* asAssignExpr() { return this; }

  gc<LValue> lvalue() const { return lvalue_; }
  gc<Expr> value() const { return value_; }

  virtual void reach()
  {
    lvalue_.reach();
    value_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<LValue> lvalue_;
  gc<Expr> value_;
  NO_COPY(AssignExpr);
};

class AsyncExpr : public Expr
{
public:
  AsyncExpr(gc<SourcePos> pos, gc<Expr> body)
  : Expr(pos),
    body_(body),
    resolved_()
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual AsyncExpr* asAsyncExpr() { return this; }

  gc<Expr> body() const { return body_; }
  ResolvedProcedure& resolved() { return resolved_; }

  virtual void reach()
  {
    body_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> body_;
  ResolvedProcedure resolved_;
  NO_COPY(AsyncExpr);
};

class BoolExpr : public Expr
{
public:
  BoolExpr(gc<SourcePos> pos, bool value)
  : Expr(pos),
    value_(value)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual BoolExpr* asBoolExpr() { return this; }

  bool value() const { return value_; }

  virtual void trace(std::ostream& out) const;

private:
  bool value_;
  NO_COPY(BoolExpr);
};

class BreakExpr : public Expr
{
public:
  BreakExpr(gc<SourcePos> pos)
  : Expr(pos)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual BreakExpr* asBreakExpr() { return this; }


  virtual void trace(std::ostream& out) const;

private:
  NO_COPY(BreakExpr);
};

class CallExpr : public Expr
{
public:
  CallExpr(gc<SourcePos> pos, gc<Expr> leftArg, gc<String> name, gc<Expr> rightArg)
  : Expr(pos),
    leftArg_(leftArg),
    name_(name),
    rightArg_(rightArg),
    resolved_(-1)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual CallExpr* asCallExpr() { return this; }

  gc<Expr> leftArg() const { return leftArg_; }
  gc<String> name() const { return name_; }
  gc<Expr> rightArg() const { return rightArg_; }
  int resolved() const { return resolved_; }
  void setResolved(int resolved) { resolved_ = resolved; }

  virtual void reach()
  {
    leftArg_.reach();
    name_.reach();
    rightArg_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> leftArg_;
  gc<String> name_;
  gc<Expr> rightArg_;
  int resolved_;
  NO_COPY(CallExpr);
};

class CatchExpr : public Expr
{
public:
  CatchExpr(gc<SourcePos> pos, gc<Expr> body, const Array<MatchClause>& catches)
  : Expr(pos),
    body_(body),
    catches_(catches)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual CatchExpr* asCatchExpr() { return this; }

  gc<Expr> body() const { return body_; }
  const Array<MatchClause>& catches() const { return catches_; }

  virtual void reach()
  {
    body_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> body_;
  Array<MatchClause> catches_;
  NO_COPY(CatchExpr);
};

class CharacterExpr : public Expr
{
public:
  CharacterExpr(gc<SourcePos> pos, unsigned int value)
  : Expr(pos),
    value_(value)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual CharacterExpr* asCharacterExpr() { return this; }

  unsigned int value() const { return value_; }

  virtual void trace(std::ostream& out) const;

private:
  unsigned int value_;
  NO_COPY(CharacterExpr);
};

class DefExpr : public Expr
{
public:
  DefExpr(gc<SourcePos> pos, gc<Pattern> leftParam, gc<String> name, gc<Pattern> rightParam, gc<Pattern> value, gc<Expr> body)
  : Expr(pos),
    leftParam_(leftParam),
    name_(name),
    rightParam_(rightParam),
    value_(value),
    body_(body),
    resolved_()
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual DefExpr* asDefExpr() { return this; }

  gc<Pattern> leftParam() const { return leftParam_; }
  gc<String> name() const { return name_; }
  gc<Pattern> rightParam() const { return rightParam_; }
  gc<Pattern> value() const { return value_; }
  gc<Expr> body() const { return body_; }
  ResolvedProcedure& resolved() { return resolved_; }

  virtual void reach()
  {
    leftParam_.reach();
    name_.reach();
    rightParam_.reach();
    value_.reach();
    body_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Pattern> leftParam_;
  gc<String> name_;
  gc<Pattern> rightParam_;
  gc<Pattern> value_;
  gc<Expr> body_;
  ResolvedProcedure resolved_;
  NO_COPY(DefExpr);
};

class DefClassExpr : public Expr
{
public:
  DefClassExpr(gc<SourcePos> pos, gc<String> name, bool isNative, const Array<gc<Expr> >& superclasses, const Array<gc<ClassField> >& fields)
  : Expr(pos),
    name_(name),
    isNative_(isNative),
    superclasses_(superclasses),
    fields_(fields),
    resolved_(),
    synthesizedMethods_()
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual DefClassExpr* asDefClassExpr() { return this; }

  gc<String> name() const { return name_; }
  bool isNative() const { return isNative_; }
  const Array<gc<Expr> >& superclasses() const { return superclasses_; }
  const Array<gc<ClassField> >& fields() const { return fields_; }
  gc<ResolvedName> resolved() const { return resolved_; }
  void setResolved(gc<ResolvedName> resolved) { resolved_ = resolved; }
  const Array<gc<DefExpr> >& synthesizedMethods() const { return synthesizedMethods_; }
  void setSynthesizedMethods(Array<gc<DefExpr> > synthesizedMethods) { synthesizedMethods_ = synthesizedMethods; }

  virtual void reach()
  {
    name_.reach();
    superclasses_.reach();
    fields_.reach();
    resolved_.reach();
    synthesizedMethods_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<String> name_;
  bool isNative_;
  Array<gc<Expr> > superclasses_;
  Array<gc<ClassField> > fields_;
  gc<ResolvedName> resolved_;
  Array<gc<DefExpr> > synthesizedMethods_;
  NO_COPY(DefClassExpr);
};

class DoExpr : public Expr
{
public:
  DoExpr(gc<SourcePos> pos, gc<Expr> body)
  : Expr(pos),
    body_(body)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual DoExpr* asDoExpr() { return this; }

  gc<Expr> body() const { return body_; }

  virtual void reach()
  {
    body_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> body_;
  NO_COPY(DoExpr);
};

class FloatExpr : public Expr
{
public:
  FloatExpr(gc<SourcePos> pos, double value)
  : Expr(pos),
    value_(value)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual FloatExpr* asFloatExpr() { return this; }

  double value() const { return value_; }

  virtual void trace(std::ostream& out) const;

private:
  double value_;
  NO_COPY(FloatExpr);
};

class FnExpr : public Expr
{
public:
  FnExpr(gc<SourcePos> pos, gc<Pattern> pattern, gc<Expr> body)
  : Expr(pos),
    pattern_(pattern),
    body_(body),
    resolved_()
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual FnExpr* asFnExpr() { return this; }

  gc<Pattern> pattern() const { return pattern_; }
  gc<Expr> body() const { return body_; }
  ResolvedProcedure& resolved() { return resolved_; }

  virtual void reach()
  {
    pattern_.reach();
    body_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Pattern> pattern_;
  gc<Expr> body_;
  ResolvedProcedure resolved_;
  NO_COPY(FnExpr);
};

class ForExpr : public Expr
{
public:
  ForExpr(gc<SourcePos> pos, gc<Pattern> pattern, gc<Expr> iterator, gc<Expr> body)
  : Expr(pos),
    pattern_(pattern),
    iterator_(iterator),
    body_(body)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual ForExpr* asForExpr() { return this; }

  gc<Pattern> pattern() const { return pattern_; }
  gc<Expr> iterator() const { return iterator_; }
  gc<Expr> body() const { return body_; }

  virtual void reach()
  {
    pattern_.reach();
    iterator_.reach();
    body_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Pattern> pattern_;
  gc<Expr> iterator_;
  gc<Expr> body_;
  NO_COPY(ForExpr);
};

class GetFieldExpr : public Expr
{
public:
  GetFieldExpr(gc<SourcePos> pos, int index)
  : Expr(pos),
    index_(index)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual GetFieldExpr* asGetFieldExpr() { return this; }

  int index() const { return index_; }

  virtual void trace(std::ostream& out) const;

private:
  int index_;
  NO_COPY(GetFieldExpr);
};

class IfExpr : public Expr
{
public:
  IfExpr(gc<SourcePos> pos, gc<Expr> condition, gc<Expr> thenArm, gc<Expr> elseArm)
  : Expr(pos),
    condition_(condition),
    thenArm_(thenArm),
    elseArm_(elseArm)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual IfExpr* asIfExpr() { return this; }

  gc<Expr> condition() const { return condition_; }
  gc<Expr> thenArm() const { return thenArm_; }
  gc<Expr> elseArm() const { return elseArm_; }

  virtual void reach()
  {
    condition_.reach();
    thenArm_.reach();
    elseArm_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> condition_;
  gc<Expr> thenArm_;
  gc<Expr> elseArm_;
  NO_COPY(IfExpr);
};

class ImportExpr : public Expr
{
public:
  ImportExpr(gc<SourcePos> pos, gc<String> name)
  : Expr(pos),
    name_(name)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual ImportExpr* asImportExpr() { return this; }

  gc<String> name() const { return name_; }

  virtual void reach()
  {
    name_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<String> name_;
  NO_COPY(ImportExpr);
};

class IntExpr : public Expr
{
public:
  IntExpr(gc<SourcePos> pos, int value)
  : Expr(pos),
    value_(value)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual IntExpr* asIntExpr() { return this; }

  int value() const { return value_; }

  virtual void trace(std::ostream& out) const;

private:
  int value_;
  NO_COPY(IntExpr);
};

class IsExpr : public Expr
{
public:
  IsExpr(gc<SourcePos> pos, gc<Expr> value, gc<Expr> type)
  : Expr(pos),
    value_(value),
    type_(type)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual IsExpr* asIsExpr() { return this; }

  gc<Expr> value() const { return value_; }
  gc<Expr> type() const { return type_; }

  virtual void reach()
  {
    value_.reach();
    type_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> value_;
  gc<Expr> type_;
  NO_COPY(IsExpr);
};

class ListExpr : public Expr
{
public:
  ListExpr(gc<SourcePos> pos, const Array<gc<Expr> >& elements)
  : Expr(pos),
    elements_(elements)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual ListExpr* asListExpr() { return this; }

  const Array<gc<Expr> >& elements() const { return elements_; }

  virtual void reach()
  {
    elements_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  Array<gc<Expr> > elements_;
  NO_COPY(ListExpr);
};

class MatchExpr : public Expr
{
public:
  MatchExpr(gc<SourcePos> pos, gc<Expr> value, const Array<MatchClause>& cases)
  : Expr(pos),
    value_(value),
    cases_(cases)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual MatchExpr* asMatchExpr() { return this; }

  gc<Expr> value() const { return value_; }
  const Array<MatchClause>& cases() const { return cases_; }

  virtual void reach()
  {
    value_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> value_;
  Array<MatchClause> cases_;
  NO_COPY(MatchExpr);
};

class NameExpr : public Expr
{
public:
  NameExpr(gc<SourcePos> pos, gc<String> name)
  : Expr(pos),
    name_(name),
    resolved_()
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual NameExpr* asNameExpr() { return this; }

  gc<String> name() const { return name_; }
  gc<ResolvedName> resolved() const { return resolved_; }
  void setResolved(gc<ResolvedName> resolved) { resolved_ = resolved; }

  virtual void reach()
  {
    name_.reach();
    resolved_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<String> name_;
  gc<ResolvedName> resolved_;
  NO_COPY(NameExpr);
};

class NativeExpr : public Expr
{
public:
  NativeExpr(gc<SourcePos> pos, gc<String> name)
  : Expr(pos),
    name_(name),
    index_(-1)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual NativeExpr* asNativeExpr() { return this; }

  gc<String> name() const { return name_; }
  int index() const { return index_; }
  void setIndex(int index) { index_ = index; }

  virtual void reach()
  {
    name_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<String> name_;
  int index_;
  NO_COPY(NativeExpr);
};

class NotExpr : public Expr
{
public:
  NotExpr(gc<SourcePos> pos, gc<Expr> value)
  : Expr(pos),
    value_(value)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual NotExpr* asNotExpr() { return this; }

  gc<Expr> value() const { return value_; }

  virtual void reach()
  {
    value_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> value_;
  NO_COPY(NotExpr);
};

class NothingExpr : public Expr
{
public:
  NothingExpr(gc<SourcePos> pos)
  : Expr(pos)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual NothingExpr* asNothingExpr() { return this; }


  virtual void trace(std::ostream& out) const;

private:
  NO_COPY(NothingExpr);
};

class OrExpr : public Expr
{
public:
  OrExpr(gc<SourcePos> pos, gc<Expr> left, gc<Expr> right)
  : Expr(pos),
    left_(left),
    right_(right)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual OrExpr* asOrExpr() { return this; }

  gc<Expr> left() const { return left_; }
  gc<Expr> right() const { return right_; }

  virtual void reach()
  {
    left_.reach();
    right_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> left_;
  gc<Expr> right_;
  NO_COPY(OrExpr);
};

class RecordExpr : public Expr
{
public:
  RecordExpr(gc<SourcePos> pos, const Array<Field>& fields)
  : Expr(pos),
    fields_(fields)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual RecordExpr* asRecordExpr() { return this; }

  const Array<Field>& fields() const { return fields_; }

  virtual void reach()
  {

    for (int i = 0; i < fields_.count(); i++)
    {
        fields_[i].name.reach();
        fields_[i].value.reach();
    }
  }

  virtual void trace(std::ostream& out) const;

private:
  Array<Field> fields_;
  NO_COPY(RecordExpr);
};

class ReturnExpr : public Expr
{
public:
  ReturnExpr(gc<SourcePos> pos, gc<Expr> value)
  : Expr(pos),
    value_(value)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual ReturnExpr* asReturnExpr() { return this; }

  gc<Expr> value() const { return value_; }

  virtual void reach()
  {
    value_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> value_;
  NO_COPY(ReturnExpr);
};

class SequenceExpr : public Expr
{
public:
  SequenceExpr(gc<SourcePos> pos, const Array<gc<Expr> >& expressions)
  : Expr(pos),
    expressions_(expressions)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual SequenceExpr* asSequenceExpr() { return this; }

  const Array<gc<Expr> >& expressions() const { return expressions_; }

  virtual void reach()
  {
    expressions_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  Array<gc<Expr> > expressions_;
  NO_COPY(SequenceExpr);
};

class SetFieldExpr : public Expr
{
public:
  SetFieldExpr(gc<SourcePos> pos, int index)
  : Expr(pos),
    index_(index)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual SetFieldExpr* asSetFieldExpr() { return this; }

  int index() const { return index_; }

  virtual void trace(std::ostream& out) const;

private:
  int index_;
  NO_COPY(SetFieldExpr);
};

class StringExpr : public Expr
{
public:
  StringExpr(gc<SourcePos> pos, gc<String> value)
  : Expr(pos),
    value_(value)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual StringExpr* asStringExpr() { return this; }

  gc<String> value() const { return value_; }

  virtual void reach()
  {
    value_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<String> value_;
  NO_COPY(StringExpr);
};

class ThrowExpr : public Expr
{
public:
  ThrowExpr(gc<SourcePos> pos, gc<Expr> value)
  : Expr(pos),
    value_(value)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual ThrowExpr* asThrowExpr() { return this; }

  gc<Expr> value() const { return value_; }

  virtual void reach()
  {
    value_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> value_;
  NO_COPY(ThrowExpr);
};

class VariableExpr : public Expr
{
public:
  VariableExpr(gc<SourcePos> pos, bool isMutable, gc<Pattern> pattern, gc<Expr> value)
  : Expr(pos),
    isMutable_(isMutable),
    pattern_(pattern),
    value_(value)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual VariableExpr* asVariableExpr() { return this; }

  bool isMutable() const { return isMutable_; }
  gc<Pattern> pattern() const { return pattern_; }
  gc<Expr> value() const { return value_; }

  virtual void reach()
  {
    pattern_.reach();
    value_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  bool isMutable_;
  gc<Pattern> pattern_;
  gc<Expr> value_;
  NO_COPY(VariableExpr);
};

class WhileExpr : public Expr
{
public:
  WhileExpr(gc<SourcePos> pos, gc<Expr> condition, gc<Expr> body)
  : Expr(pos),
    condition_(condition),
    body_(body)
  {}

  virtual void accept(ExprVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual WhileExpr* asWhileExpr() { return this; }

  gc<Expr> condition() const { return condition_; }
  gc<Expr> body() const { return body_; }

  virtual void reach()
  {
    condition_.reach();
    body_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> condition_;
  gc<Expr> body_;
  NO_COPY(WhileExpr);
};

class LValueVisitor
{
public:
  virtual ~LValueVisitor() {}

  virtual void visit(CallLValue& node, int arg) = 0;
  virtual void visit(NameLValue& node, int arg) = 0;
  virtual void visit(RecordLValue& node, int arg) = 0;
  virtual void visit(WildcardLValue& node, int arg) = 0;

protected:
  LValueVisitor() {}

private:
  NO_COPY(LValueVisitor);
};

class LValue : public Managed
{
public:
  LValue(gc<SourcePos> pos)
  : pos_(pos)
  {}

  virtual ~LValue() {}

  // The visitor pattern.
  virtual void accept(LValueVisitor& visitor, int arg) = 0;

  // Dynamic casts.
  virtual CallLValue* asCallLValue() { return NULL; }
  virtual NameLValue* asNameLValue() { return NULL; }
  virtual RecordLValue* asRecordLValue() { return NULL; }
  virtual WildcardLValue* asWildcardLValue() { return NULL; }

  gc<SourcePos> pos() const { return pos_; }

private:
  gc<SourcePos> pos_;
};

class CallLValue : public LValue
{
public:
  CallLValue(gc<SourcePos> pos, gc<CallExpr> call)
  : LValue(pos),
    call_(call)
  {}

  virtual void accept(LValueVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual CallLValue* asCallLValue() { return this; }

  gc<CallExpr> call() const { return call_; }

  virtual void reach()
  {
    call_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<CallExpr> call_;
  NO_COPY(CallLValue);
};

class NameLValue : public LValue
{
public:
  NameLValue(gc<SourcePos> pos, gc<String> name)
  : LValue(pos),
    name_(name),
    resolved_()
  {}

  virtual void accept(LValueVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual NameLValue* asNameLValue() { return this; }

  gc<String> name() const { return name_; }
  gc<ResolvedName> resolved() const { return resolved_; }
  void setResolved(gc<ResolvedName> resolved) { resolved_ = resolved; }

  virtual void reach()
  {
    name_.reach();
    resolved_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<String> name_;
  gc<ResolvedName> resolved_;
  NO_COPY(NameLValue);
};

class RecordLValue : public LValue
{
public:
  RecordLValue(gc<SourcePos> pos, const Array<LValueField>& fields)
  : LValue(pos),
    fields_(fields)
  {}

  virtual void accept(LValueVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual RecordLValue* asRecordLValue() { return this; }

  const Array<LValueField>& fields() const { return fields_; }

  virtual void reach()
  {

    for (int i = 0; i < fields_.count(); i++)
    {
        fields_[i].name.reach();
        fields_[i].value.reach();
    }
  }

  virtual void trace(std::ostream& out) const;

private:
  Array<LValueField> fields_;
  NO_COPY(RecordLValue);
};

class WildcardLValue : public LValue
{
public:
  WildcardLValue(gc<SourcePos> pos)
  : LValue(pos)
  {}

  virtual void accept(LValueVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual WildcardLValue* asWildcardLValue() { return this; }


  virtual void trace(std::ostream& out) const;

private:
  NO_COPY(WildcardLValue);
};

class PatternVisitor
{
public:
  virtual ~PatternVisitor() {}

  virtual void visit(RecordPattern& node, int arg) = 0;
  virtual void visit(TypePattern& node, int arg) = 0;
  virtual void visit(ValuePattern& node, int arg) = 0;
  virtual void visit(VariablePattern& node, int arg) = 0;

protected:
  PatternVisitor() {}

private:
  NO_COPY(PatternVisitor);
};

class Pattern : public Managed
{
public:
  Pattern(gc<SourcePos> pos)
  : pos_(pos)
  {}

  virtual ~Pattern() {}

  // The visitor pattern.
  virtual void accept(PatternVisitor& visitor, int arg) = 0;

  // Dynamic casts.
  virtual RecordPattern* asRecordPattern() { return NULL; }
  virtual TypePattern* asTypePattern() { return NULL; }
  virtual ValuePattern* asValuePattern() { return NULL; }
  virtual VariablePattern* asVariablePattern() { return NULL; }

  gc<SourcePos> pos() const { return pos_; }

private:
  gc<SourcePos> pos_;
};

class RecordPattern : public Pattern
{
public:
  RecordPattern(gc<SourcePos> pos, const Array<PatternField>& fields)
  : Pattern(pos),
    fields_(fields)
  {}

  virtual void accept(PatternVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual RecordPattern* asRecordPattern() { return this; }

  const Array<PatternField>& fields() const { return fields_; }

  virtual void reach()
  {

    for (int i = 0; i < fields_.count(); i++)
    {
        fields_[i].name.reach();
        fields_[i].value.reach();
    }
  }

  virtual void trace(std::ostream& out) const;

private:
  Array<PatternField> fields_;
  NO_COPY(RecordPattern);
};

class TypePattern : public Pattern
{
public:
  TypePattern(gc<SourcePos> pos, gc<Expr> type)
  : Pattern(pos),
    type_(type)
  {}

  virtual void accept(PatternVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual TypePattern* asTypePattern() { return this; }

  gc<Expr> type() const { return type_; }

  virtual void reach()
  {
    type_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> type_;
  NO_COPY(TypePattern);
};

class ValuePattern : public Pattern
{
public:
  ValuePattern(gc<SourcePos> pos, gc<Expr> value)
  : Pattern(pos),
    value_(value)
  {}

  virtual void accept(PatternVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual ValuePattern* asValuePattern() { return this; }

  gc<Expr> value() const { return value_; }

  virtual void reach()
  {
    value_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<Expr> value_;
  NO_COPY(ValuePattern);
};

class VariablePattern : public Pattern
{
public:
  VariablePattern(gc<SourcePos> pos, gc<String> name, gc<Pattern> pattern)
  : Pattern(pos),
    name_(name),
    pattern_(pattern),
    resolved_()
  {}

  virtual void accept(PatternVisitor& visitor, int arg)
  {
    visitor.visit(*this, arg);
  }

  virtual VariablePattern* asVariablePattern() { return this; }

  gc<String> name() const { return name_; }
  gc<Pattern> pattern() const { return pattern_; }
  gc<ResolvedName> resolved() const { return resolved_; }
  void setResolved(gc<ResolvedName> resolved) { resolved_ = resolved; }

  virtual void reach()
  {
    name_.reach();
    pattern_.reach();
    resolved_.reach();
  }

  virtual void trace(std::ostream& out) const;

private:
  gc<String> name_;
  gc<Pattern> pattern_;
  gc<ResolvedName> resolved_;
  NO_COPY(VariablePattern);
};
