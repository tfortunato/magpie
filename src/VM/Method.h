#pragma once

#include "Array.h"
#include "Bytecode.h"
#include "Macros.h"
#include "Managed.h"
#include "Memory.h"

namespace magpie
{
  class Module;
  class Object;
  
  typedef gc<Object> (*Primitive)(ArrayView<gc<Object> >& args);
  
  class Method : public Managed
  {
  public:
    Method()
    : code_(),
      constants_(),
      numSlots_(0),
      primitive_(NULL)
    {}
    
    Method(Primitive primitive)
    : code_(),
      constants_(),
      numSlots_(0),
      primitive_(primitive)
    {}
    
    void setCode(const Array<instruction>& code,
                 int maxSlots);
    
    inline const Array<instruction>& code() const { return code_; }
    inline Primitive primitive() const { return primitive_; }
    
    int addConstant(gc<Object> constant);
    gc<Object> getConstant(int index) const;
    
    int numSlots() const { return numSlots_; }

    void debugTrace() const;
    void debugTrace(instruction ins) const;

    virtual void reach();
    
  private:
    Array<instruction> code_;
    Array<gc<Object> > constants_;
    
    int numSlots_;
    
    // The primitive function for this method. Will be NULL for non-primitive
    // methods.
    Primitive primitive_;
    
    NO_COPY(Method);
  };

  class MethodScope
  {
  public:
    int declare(gc<String> name);
    void define(int index, gc<Method> method);
    void define(gc<String> name, gc<Method> method);
    void define(gc<String> name, Primitive primitive);
    
    int find(gc<String> name) const;
    gc<Method> get(int index) const { return methods_[index]; }
    
    void reach();
    
  private:
    Array<gc<Method> > methods_;
    Array<gc<String> > names_;
  };
}