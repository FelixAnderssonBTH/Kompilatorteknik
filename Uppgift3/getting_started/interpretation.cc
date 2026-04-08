class Program {
  map methods;
}

class Method {
  list variables;
  list instructions;
}

class Instruction {
  int id;
  object argument;
}

class Activation {
  int pc;
  map local_variable_values;
  Method method;
}

class Interpreter {
  Program program;
  Method main;

  Interpreter(Program p) {
    program = p;
    main = program.getMethod(program.getMainMethod);
  }

  void execute() {
    Method m = main;
    Activation current_activation = new Activation(0, m);
    int instruction_id = -1;
    Stack<Activation> activations_stack = new Stack();

    while (instruction_id != STOP) {
      instruction = current_activation.getNextInstruction();
      switch (instruction.id) {
      case ICONST:
        data_stack.push(instruction.argument);
      case ISTORE:
        current_activation.storeValue(instruction.argument, data_stack.pop());
      case IADD:
        data_stack.push(data_stack.pop() + data_stack.pop());
      }
    }
  }
}
