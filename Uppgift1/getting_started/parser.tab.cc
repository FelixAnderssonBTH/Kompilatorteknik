// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 13 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_Recursive_ClassDeclaration: // Recursive_ClassDeclaration
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_Recursive_ClassDeclarationVar: // Recursive_ClassDeclarationVar
      case symbol_kind::S_Recursive_ClassDeclarationMeth: // Recursive_ClassDeclarationMeth
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodDeclaration_Body: // MethodDeclaration_Body
      case symbol_kind::S_MethodDeclaration_Variables: // MethodDeclaration_Variables
      case symbol_kind::S_Recursive_MethodDeclaration: // Recursive_MethodDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Recursive_statement: // Recursive_statement
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Recursive_Expression: // Recursive_Expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_Identifier: // Identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LS: // LS
      case symbol_kind::S_RS: // RS
      case symbol_kind::S_COM: // COM
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_EUQUAL_SIGN: // EUQUAL_SIGN
      case symbol_kind::S_SEMI: // SEMI
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_LENGHT: // LENGHT
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_SUBOP: // SUBOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_LEFT_ARROW: // LEFT_ARROW
      case symbol_kind::S_RIGHT_ARROW: // RIGHT_ARROW
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_Recursive_ClassDeclaration: // Recursive_ClassDeclaration
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_Recursive_ClassDeclarationVar: // Recursive_ClassDeclarationVar
      case symbol_kind::S_Recursive_ClassDeclarationMeth: // Recursive_ClassDeclarationMeth
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodDeclaration_Body: // MethodDeclaration_Body
      case symbol_kind::S_MethodDeclaration_Variables: // MethodDeclaration_Variables
      case symbol_kind::S_Recursive_MethodDeclaration: // Recursive_MethodDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Recursive_statement: // Recursive_statement
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Recursive_Expression: // Recursive_Expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_Identifier: // Identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LS: // LS
      case symbol_kind::S_RS: // RS
      case symbol_kind::S_COM: // COM
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_EUQUAL_SIGN: // EUQUAL_SIGN
      case symbol_kind::S_SEMI: // SEMI
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_LENGHT: // LENGHT
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_SUBOP: // SUBOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_LEFT_ARROW: // LEFT_ARROW
      case symbol_kind::S_RIGHT_ARROW: // RIGHT_ARROW
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_Recursive_ClassDeclaration: // Recursive_ClassDeclaration
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_Recursive_ClassDeclarationVar: // Recursive_ClassDeclarationVar
      case symbol_kind::S_Recursive_ClassDeclarationMeth: // Recursive_ClassDeclarationMeth
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodDeclaration_Body: // MethodDeclaration_Body
      case symbol_kind::S_MethodDeclaration_Variables: // MethodDeclaration_Variables
      case symbol_kind::S_Recursive_MethodDeclaration: // Recursive_MethodDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Recursive_statement: // Recursive_statement
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Recursive_Expression: // Recursive_Expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_Identifier: // Identifier
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LS: // LS
      case symbol_kind::S_RS: // RS
      case symbol_kind::S_COM: // COM
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_EUQUAL_SIGN: // EUQUAL_SIGN
      case symbol_kind::S_SEMI: // SEMI
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_LENGHT: // LENGHT
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_SUBOP: // SUBOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_LEFT_ARROW: // LEFT_ARROW
      case symbol_kind::S_RIGHT_ARROW: // RIGHT_ARROW
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_Recursive_ClassDeclaration: // Recursive_ClassDeclaration
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_Recursive_ClassDeclarationVar: // Recursive_ClassDeclarationVar
      case symbol_kind::S_Recursive_ClassDeclarationMeth: // Recursive_ClassDeclarationMeth
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodDeclaration_Body: // MethodDeclaration_Body
      case symbol_kind::S_MethodDeclaration_Variables: // MethodDeclaration_Variables
      case symbol_kind::S_Recursive_MethodDeclaration: // Recursive_MethodDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Recursive_statement: // Recursive_statement
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Recursive_Expression: // Recursive_Expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_Identifier: // Identifier
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LS: // LS
      case symbol_kind::S_RS: // RS
      case symbol_kind::S_COM: // COM
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_EUQUAL_SIGN: // EUQUAL_SIGN
      case symbol_kind::S_SEMI: // SEMI
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_LENGHT: // LENGHT
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_SUBOP: // SUBOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_LEFT_ARROW: // LEFT_ARROW
      case symbol_kind::S_RIGHT_ARROW: // RIGHT_ARROW
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_Recursive_ClassDeclaration: // Recursive_ClassDeclaration
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_Recursive_ClassDeclarationVar: // Recursive_ClassDeclarationVar
      case symbol_kind::S_Recursive_ClassDeclarationMeth: // Recursive_ClassDeclarationMeth
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodDeclaration_Body: // MethodDeclaration_Body
      case symbol_kind::S_MethodDeclaration_Variables: // MethodDeclaration_Variables
      case symbol_kind::S_Recursive_MethodDeclaration: // Recursive_MethodDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Recursive_statement: // Recursive_statement
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Recursive_Expression: // Recursive_Expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_Identifier: // Identifier
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LS: // LS
      case symbol_kind::S_RS: // RS
      case symbol_kind::S_COM: // COM
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_EUQUAL_SIGN: // EUQUAL_SIGN
      case symbol_kind::S_SEMI: // SEMI
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_LENGHT: // LENGHT
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_SUBOP: // SUBOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_LEFT_ARROW: // LEFT_ARROW
      case symbol_kind::S_RIGHT_ARROW: // RIGHT_ARROW
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // Goal: MainClass "end of file"
#line 44 "parser.yy"
                     {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); root = yylhs.value.as < Node * > ();}
#line 828 "parser.tab.cc"
    break;

  case 3: // Goal: MainClass Recursive_ClassDeclaration "end of file"
#line 45 "parser.yy"
                                                       {yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); root = yylhs.value.as < Node * > ();}
#line 834 "parser.tab.cc"
    break;

  case 4: // Recursive_ClassDeclaration: ClassDeclaration
#line 47 "parser.yy"
                                             {yylhs.value.as < Node * > () = new Node("Recursive_ClassDeclaration", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 840 "parser.tab.cc"
    break;

  case 5: // Recursive_ClassDeclaration: Recursive_ClassDeclaration ClassDeclaration
#line 48 "parser.yy"
                                                          {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 846 "parser.tab.cc"
    break;

  case 6: // MainClass: PUBLIC CLASS Identifier LB PUBLIC STATIC VOID MAIN LP STRING LS RS Identifier RP LB Recursive_statement RB RB
#line 51 "parser.yy"
                                                                                                              {yylhs.value.as < Node * > () = new Node("Main Class", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());}
#line 852 "parser.tab.cc"
    break;

  case 7: // ClassDeclaration: CLASS Identifier LB RB
#line 53 "parser.yy"
                                         {yylhs.value.as < Node * > () = new Node("EmptyClass", "", yylineno);yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());}
#line 858 "parser.tab.cc"
    break;

  case 8: // ClassDeclaration: CLASS Identifier LB Recursive_ClassDeclarationVar RB
#line 54 "parser.yy"
                                                                   {yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 864 "parser.tab.cc"
    break;

  case 9: // ClassDeclaration: CLASS Identifier LB Recursive_ClassDeclarationMeth RB
#line 55 "parser.yy"
                                                                   {yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 870 "parser.tab.cc"
    break;

  case 10: // ClassDeclaration: CLASS Identifier LB Recursive_ClassDeclarationVar Recursive_ClassDeclarationMeth RB
#line 56 "parser.yy"
                                                                                                 {yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 876 "parser.tab.cc"
    break;

  case 11: // Recursive_ClassDeclarationVar: VarDeclaration
#line 58 "parser.yy"
                                              {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 882 "parser.tab.cc"
    break;

  case 12: // Recursive_ClassDeclarationVar: Recursive_ClassDeclarationVar VarDeclaration
#line 59 "parser.yy"
                                                           { yylhs.value.as < Node * > () = new Node("VarDeclaration", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 888 "parser.tab.cc"
    break;

  case 13: // Recursive_ClassDeclarationMeth: MethodDeclaration
#line 62 "parser.yy"
                                {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 894 "parser.tab.cc"
    break;

  case 14: // Recursive_ClassDeclarationMeth: Recursive_ClassDeclarationMeth MethodDeclaration
#line 63 "parser.yy"
                                                               { yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 900 "parser.tab.cc"
    break;

  case 15: // VarDeclaration: Type Identifier SEMI
#line 65 "parser.yy"
                                      {yylhs.value.as < Node * > () = new Node("VarDeclaration", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 906 "parser.tab.cc"
    break;

  case 16: // MethodDeclaration: PUBLIC Type Identifier LP RP LB MethodDeclaration_Body RB
#line 67 "parser.yy"
                                                                             {yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 912 "parser.tab.cc"
    break;

  case 17: // MethodDeclaration: PUBLIC Type Identifier LP MethodDeclaration_Variables RP LB MethodDeclaration_Body RB
#line 68 "parser.yy"
                                                                                                    {yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 918 "parser.tab.cc"
    break;

  case 18: // MethodDeclaration_Body: RETURN Expression SEMI
#line 70 "parser.yy"
                                               {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();}
#line 924 "parser.tab.cc"
    break;

  case 19: // MethodDeclaration_Body: Recursive_MethodDeclaration RETURN Expression SEMI
#line 71 "parser.yy"
                                                                 {yylhs.value.as < Node * > () = new Node("MethodDeclaration_Body", "", yylineno);yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 930 "parser.tab.cc"
    break;

  case 20: // MethodDeclaration_Variables: Type Identifier
#line 73 "parser.yy"
                                             {yylhs.value.as < Node * > () = new Node("MethodDeclaration_Variables", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 936 "parser.tab.cc"
    break;

  case 21: // MethodDeclaration_Variables: MethodDeclaration_Variables COM Type Identifier
#line 74 "parser.yy"
                                                              {yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 942 "parser.tab.cc"
    break;

  case 22: // Recursive_MethodDeclaration: VarDeclaration
#line 76 "parser.yy"
                                            {yylhs.value.as < Node * > () = new Node("MethodDeclaration_Variables", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 948 "parser.tab.cc"
    break;

  case 23: // Recursive_MethodDeclaration: Recursive_MethodDeclaration VarDeclaration
#line 77 "parser.yy"
                                                         {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 954 "parser.tab.cc"
    break;

  case 24: // Recursive_MethodDeclaration: Statement
#line 78 "parser.yy"
                        {yylhs.value.as < Node * > () = new Node("MethodDeclaration_Statements", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 960 "parser.tab.cc"
    break;

  case 25: // Recursive_MethodDeclaration: Recursive_MethodDeclaration Statement
#line 79 "parser.yy"
                                                    {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 966 "parser.tab.cc"
    break;

  case 26: // Type: INTEGER LS RS
#line 81 "parser.yy"
                    {yylhs.value.as < Node * > () = new Node("Type", "int[]", yylineno);}
#line 972 "parser.tab.cc"
    break;

  case 27: // Type: BOOL
#line 82 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("Type", "boolean", yylineno);}
#line 978 "parser.tab.cc"
    break;

  case 28: // Type: INTEGER
#line 83 "parser.yy"
                      {yylhs.value.as < Node * > () = new Node("Type", "integer", yylineno);}
#line 984 "parser.tab.cc"
    break;

  case 29: // Type: Identifier
#line 84 "parser.yy"
                         {yylhs.value.as < Node * > () = new Node("Type", "Identifier", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 990 "parser.tab.cc"
    break;

  case 30: // Statement: LB RB
#line 87 "parser.yy"
      { yylhs.value.as < Node * > () = new Node("EmptyStatement", "",yylineno); }
#line 996 "parser.tab.cc"
    break;

  case 31: // Statement: LB Recursive_statement RB
#line 88 "parser.yy"
                                        {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();}
#line 1002 "parser.tab.cc"
    break;

  case 32: // Statement: IF LP Expression RP Statement ELSE Statement
#line 89 "parser.yy"
                                                           {yylhs.value.as < Node * > () = new Node(" IfElseStatement", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1008 "parser.tab.cc"
    break;

  case 33: // Statement: IF LP Expression RP Statement
#line 90 "parser.yy"
                                            {yylhs.value.as < Node * > () = new Node(" IfElseStatement", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1014 "parser.tab.cc"
    break;

  case 34: // Statement: WHILE LP Expression RP Statement
#line 91 "parser.yy"
                                               {yylhs.value.as < Node * > () = new Node("WhileStatement", "", yylineno), yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()), yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1020 "parser.tab.cc"
    break;

  case 35: // Statement: PRINT LP Expression RP SEMI
#line 92 "parser.yy"
                                          {yylhs.value.as < Node * > () = new Node("PrintStatement", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());}
#line 1026 "parser.tab.cc"
    break;

  case 36: // Statement: Identifier EUQUAL_SIGN Expression SEMI
#line 93 "parser.yy"
                                                     { yylhs.value.as < Node * > () = new Node("AssinedExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1032 "parser.tab.cc"
    break;

  case 37: // Statement: Identifier LS Expression RS EUQUAL_SIGN Expression SEMI
#line 94 "parser.yy"
                                                                      { yylhs.value.as < Node * > () = new Node("AssinedExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1038 "parser.tab.cc"
    break;

  case 38: // Recursive_statement: Statement
#line 96 "parser.yy"
                               {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1044 "parser.tab.cc"
    break;

  case 39: // Recursive_statement: Recursive_statement Statement
#line 97 "parser.yy"
                                            { yylhs.value.as < Node * > () = new Node("Statement", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1050 "parser.tab.cc"
    break;

  case 40: // Expression: Expression PLUSOP Expression
#line 101 "parser.yy"
                             { yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1056 "parser.tab.cc"
    break;

  case 41: // Expression: Expression SUBOP Expression
#line 102 "parser.yy"
                                          { yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1062 "parser.tab.cc"
    break;

  case 42: // Expression: Expression MULTOP Expression
#line 103 "parser.yy"
                                           { yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1068 "parser.tab.cc"
    break;

  case 43: // Expression: Expression DIVIDE Expression
#line 104 "parser.yy"
                                           { yylhs.value.as < Node * > () = new Node("DivideExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1074 "parser.tab.cc"
    break;

  case 44: // Expression: Expression AND Expression
#line 105 "parser.yy"
                                        { yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1080 "parser.tab.cc"
    break;

  case 45: // Expression: Expression OR Expression
#line 106 "parser.yy"
                                       { yylhs.value.as < Node * > () = new Node("OrExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1086 "parser.tab.cc"
    break;

  case 46: // Expression: Expression EQUAL Expression
#line 107 "parser.yy"
                                          { yylhs.value.as < Node * > () = new Node("EqualExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1092 "parser.tab.cc"
    break;

  case 47: // Expression: Expression LEFT_ARROW Expression
#line 108 "parser.yy"
                                               { yylhs.value.as < Node * > () = new Node("LeftArrowExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1098 "parser.tab.cc"
    break;

  case 48: // Expression: Expression RIGHT_ARROW Expression
#line 109 "parser.yy"
                                                { yylhs.value.as < Node * > () = new Node("RightArrowExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1104 "parser.tab.cc"
    break;

  case 49: // Expression: Expression LS Expression RS
#line 110 "parser.yy"
                                          { yylhs.value.as < Node * > () = new Node("ArrayExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1110 "parser.tab.cc"
    break;

  case 50: // Expression: Expression DOT LENGHT
#line 111 "parser.yy"
                                    { yylhs.value.as < Node * > () = new Node("LenghtExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());}
#line 1116 "parser.tab.cc"
    break;

  case 51: // Expression: Expression DOT Identifier LP Recursive_Expression RP
#line 112 "parser.yy"
                                                                   {yylhs.value.as < Node * > () = new Node("Recursive_Expression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1122 "parser.tab.cc"
    break;

  case 52: // Expression: Expression DOT Identifier LP RP
#line 113 "parser.yy"
                                              {yylhs.value.as < Node * > () = new Node("Recursive_Expression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());}
#line 1128 "parser.tab.cc"
    break;

  case 53: // Expression: factor
#line 114 "parser.yy"
                          {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r4 ");*/}
#line 1134 "parser.tab.cc"
    break;

  case 54: // Expression: TRUE
#line 115 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("TRUE", "",yylineno);}
#line 1140 "parser.tab.cc"
    break;

  case 55: // Expression: FALSE
#line 116 "parser.yy"
                    {yylhs.value.as < Node * > () = new Node("FALSE", "",yylineno);}
#line 1146 "parser.tab.cc"
    break;

  case 56: // Expression: THIS
#line 117 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("THIS", "",yylineno);}
#line 1152 "parser.tab.cc"
    break;

  case 57: // Expression: NEW INTEGER LS Expression RS
#line 118 "parser.yy"
                                           {yylhs.value.as < Node * > () = new Node("newIntExpression", "",yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1158 "parser.tab.cc"
    break;

  case 58: // Expression: NEW Identifier LP RP
#line 119 "parser.yy"
                                   {yylhs.value.as < Node * > () = new Node("newIdentifierExpression", "",yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());}
#line 1164 "parser.tab.cc"
    break;

  case 59: // Expression: NOT Expression
#line 120 "parser.yy"
                             {yylhs.value.as < Node * > () = new Node("NotExpression", "",yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1170 "parser.tab.cc"
    break;

  case 60: // Expression: LP Expression RP
#line 121 "parser.yy"
                               {yylhs.value.as < Node * > () = new Node("BracketsExpression", "",yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1176 "parser.tab.cc"
    break;

  case 61: // Expression: Identifier
#line 122 "parser.yy"
                         {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r4 ");*/}
#line 1182 "parser.tab.cc"
    break;

  case 62: // Recursive_Expression: Expression
#line 126 "parser.yy"
                                 {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1188 "parser.tab.cc"
    break;

  case 63: // Recursive_Expression: Recursive_Expression COM Expression
#line 127 "parser.yy"
                                      { yylhs.value.as < Node * > () = new Node("Expression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1194 "parser.tab.cc"
    break;

  case 64: // factor: INT
#line 130 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1200 "parser.tab.cc"
    break;

  case 65: // Identifier: STR
#line 131 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("Str", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1206 "parser.tab.cc"
    break;


#line 1210 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -57;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -11,    18,     7,    23,     9,   -57,   -57,     9,    47,   -57,
     -57,    27,    41,   -57,   -57,    63,    -1,    77,    38,   -57,
      88,   -57,   106,     3,   -57,   -57,     9,   -57,    84,     9,
      97,   -57,    15,   -57,   -57,   -57,   102,    99,    89,   -57,
     -57,   -57,    90,    48,   105,   108,     0,     9,   133,   394,
      38,   110,   -57,   139,   123,   126,   380,   127,   122,   -57,
     125,   410,   -57,    79,     9,   394,     9,   380,   380,   -57,
     380,   -57,   -57,   -57,    69,   380,    91,   -57,   -57,   380,
     -57,   -57,   416,    79,   -57,   380,   -57,   -57,   380,   380,
     -57,   129,   132,   130,   144,   109,   156,   146,   169,   380,
       8,   -57,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   183,   -57,   -57,   222,   208,   231,   -57,   142,    53,
      53,   380,   157,   -57,   247,   -57,   159,     5,     5,   109,
     109,   334,   309,   344,    16,    16,   180,   -57,   184,   -57,
      53,   172,   -57,   270,   -57,   -57,   370,   -57,   380,   422,
      53,   -57,   -57,   295,    13,   286,   161,   -57,   380,   -57,
     -57,   -57,   295
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     1,     2,     0,     0,     4,
      65,     0,     0,     3,     5,     0,     0,     0,     0,    27,
      28,     7,     0,     0,    11,    13,     0,    29,     0,     0,
       0,     8,     0,    12,     9,    14,     0,     0,     0,    26,
      10,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,    22,
       0,     0,    24,    29,     0,     0,     0,     0,     0,    64,
       0,    54,    55,    56,     0,     0,     0,    53,    61,     0,
      30,    38,     0,     0,    16,     0,    23,    25,     0,     0,
      21,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    39,     0,     0,     0,    17,     0,     0,
       0,     0,     0,    60,     0,    50,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    19,     0,    36,
       0,    33,    34,     0,    58,    49,     0,    35,     0,     0,
       0,    57,    52,    62,     0,     0,     0,    32,     0,    51,
      37,     6,    63
  };

  const short
  parser::yypgoto_[] =
  {
     -57,   -57,   -57,   -57,   187,   -57,   174,   -12,    -2,   134,
     -57,   -57,   -10,   -56,    57,     1,   -57,   -57,    -4
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     8,     3,     9,    22,    23,    59,    25,    60,
      46,    61,    26,    62,    82,    76,   154,    77,    78
  };

  const unsigned char
  parser::yytable_[] =
  {
      11,     1,    81,    12,    24,    87,    50,     5,    29,    99,
      33,    18,    27,   100,    27,    18,    19,    20,    27,   158,
      99,    35,    36,     6,   100,    38,   113,    18,    10,     4,
      35,    51,    21,    47,     7,   125,    34,    10,    10,    27,
      64,   104,   105,    52,   159,    63,    27,    13,    40,    86,
     102,   103,   104,   105,    83,    19,    20,    63,     7,    15,
      90,    63,    92,   141,   142,    19,    20,    10,    93,    94,
      97,    95,    54,    16,    55,    17,    98,    10,    83,    45,
     111,    57,    10,    88,    81,    58,   114,    96,    89,   115,
     116,    28,    30,   113,   157,    99,   126,    37,    10,   100,
     124,   101,    39,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    41,    99,    42,    83,    83,   100,    18,    43,
      44,    48,   143,    19,    20,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    99,    10,    83,    53,   100,    31,
      49,    54,    65,    55,    66,    83,    83,   153,    99,   155,
      57,    10,   100,    67,    58,    80,    68,    79,    84,   162,
     121,   119,   117,   118,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    99,   140,   120,   122,   100,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    99,   144,   146,
     147,   100,   150,   148,   161,    14,    32,   149,     0,    91,
     123,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    99,   138,   136,     0,   100,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    99,     0,     0,     0,
     100,     0,   137,     0,     0,    99,     0,     0,     0,   100,
       0,   139,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    99,   145,     0,     0,   100,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    99,   151,     0,     0,   100,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      99,     0,     0,     0,   100,     0,   160,     0,     0,    99,
       0,     0,     0,   100,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    99,     0,     0,     0,   100,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    99,     0,
       0,     0,   100,   102,   103,   104,   105,   106,    99,   108,
     109,   110,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,     0,    69,   108,   109,   110,    70,   102,   103,
     104,   105,     0,    69,     0,   109,   110,    70,     0,     0,
       0,     0,    71,    72,    73,    74,     0,     0,     0,    10,
      75,   152,    71,    72,    73,    74,     0,     0,     0,    10,
      75,    19,    20,    54,     0,    55,     0,     0,     0,     0,
      56,     0,    57,    10,     0,     0,    58,    19,    20,    54,
       0,    55,     0,     0,     0,    54,    85,    55,    57,    10,
       0,    54,    58,    55,    57,    10,     0,     0,    58,   112,
      57,    10,     0,     0,    58,   156
  };

  const short
  parser::yycheck_[] =
  {
       4,    12,    58,     7,    16,    61,     6,     0,    18,     4,
      22,    12,    16,     8,    18,    12,    17,    18,    22,     6,
       4,    23,    26,     0,     8,    29,    82,    12,    29,    11,
      32,    31,    33,    43,    11,    27,    33,    29,    29,    43,
      50,    36,    37,    47,    31,    49,    50,     0,    33,    61,
      34,    35,    36,    37,    58,    17,    18,    61,    11,    32,
      64,    65,    66,   119,   120,    17,    18,    29,    67,    68,
      74,    70,    19,    32,    21,    12,    75,    29,    82,    31,
      79,    28,    29,     4,   140,    32,    85,    18,     9,    88,
      89,    14,     4,   149,   150,     4,   100,    13,    29,     8,
      99,    10,     5,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    10,     4,    15,   119,   120,     8,    12,    30,
      30,    16,   121,    17,    18,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     4,    29,   140,     4,     8,    33,
      32,    19,    32,    21,     5,   149,   150,   146,     4,   148,
      28,    29,     8,    30,    32,    33,    30,    30,    33,   158,
       4,    31,    33,    31,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     4,    32,    31,    30,     8,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     4,    31,    30,
      10,     8,    20,     9,    33,     8,    22,   140,    -1,    65,
      31,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     4,     5,    31,    -1,     8,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     4,    -1,    -1,    -1,
       8,    -1,    10,    -1,    -1,     4,    -1,    -1,    -1,     8,
      -1,    10,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     4,     5,    -1,    -1,     8,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     4,     5,    -1,    -1,     8,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       4,    -1,    -1,    -1,     8,    -1,    10,    -1,    -1,     4,
      -1,    -1,    -1,     8,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     4,    -1,    -1,    -1,     8,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     4,    -1,
      -1,    -1,     8,    34,    35,    36,    37,    38,     4,    40,
      41,    42,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    -1,     3,    40,    41,    42,     7,    34,    35,
      36,    37,    -1,     3,    -1,    41,    42,     7,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      30,    17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,
      26,    -1,    28,    29,    -1,    -1,    32,    17,    18,    19,
      -1,    21,    -1,    -1,    -1,    19,    26,    21,    28,    29,
      -1,    19,    32,    21,    28,    29,    -1,    -1,    32,    33,
      28,    29,    -1,    -1,    32,    33
  };

  const signed char
  parser::yystos_[] =
  {
       0,    12,    44,    46,    11,     0,     0,    11,    45,    47,
      29,    61,    61,     0,    47,    32,    32,    12,    12,    17,
      18,    33,    48,    49,    50,    51,    55,    61,    14,    55,
       4,    33,    49,    50,    33,    51,    61,    13,    61,     5,
      33,    10,    15,    30,    30,    31,    53,    55,    16,    32,
       6,    31,    61,     4,    19,    21,    26,    28,    32,    50,
      52,    54,    56,    61,    55,    32,     5,    30,    30,     3,
       7,    22,    23,    24,    25,    30,    58,    60,    61,    30,
      33,    56,    57,    61,    33,    26,    50,    56,     4,     9,
      61,    52,    61,    58,    58,    58,    18,    61,    58,     4,
       8,    10,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    58,    33,    56,    58,    58,    58,    33,    31,    31,
      31,     4,    30,    31,    58,    27,    61,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    31,    10,     5,    10,
      32,    56,    56,    58,    31,     5,    30,    10,     9,    57,
      20,     5,    31,    58,    59,    58,    33,    56,     6,    31,
      10,    33,    58
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    44,    45,    45,    46,    47,    47,    47,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    61
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     3,     1,     2,    18,     4,     5,     5,
       6,     1,     2,     1,     2,     3,     8,     9,     3,     4,
       2,     4,     1,     2,     1,     2,     3,     1,     1,     1,
       2,     3,     7,     5,     5,     5,     4,     7,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     6,     5,     1,     1,     1,     1,     5,     4,     2,
       3,     1,     1,     3,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INT", "LS", "RS",
  "COM", "NOT", "DOT", "EUQUAL_SIGN", "SEMI", "CLASS", "PUBLIC", "VOID",
  "STATIC", "MAIN", "STRING", "BOOL", "INTEGER", "IF", "ELSE", "WHILE",
  "TRUE", "FALSE", "THIS", "NEW", "RETURN", "LENGHT", "PRINT", "STR", "LP",
  "RP", "LB", "RB", "PLUSOP", "SUBOP", "MULTOP", "DIVIDE", "AND", "OR",
  "EQUAL", "LEFT_ARROW", "RIGHT_ARROW", "$accept", "Goal",
  "Recursive_ClassDeclaration", "MainClass", "ClassDeclaration",
  "Recursive_ClassDeclarationVar", "Recursive_ClassDeclarationMeth",
  "VarDeclaration", "MethodDeclaration", "MethodDeclaration_Body",
  "MethodDeclaration_Variables", "Recursive_MethodDeclaration", "Type",
  "Statement", "Recursive_statement", "Expression", "Recursive_Expression",
  "factor", "Identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    44,    44,    45,    47,    48,    51,    53,    54,    55,
      56,    58,    59,    62,    63,    65,    67,    68,    70,    71,
      73,    74,    76,    77,    78,    79,    81,    82,    83,    84,
      87,    88,    89,    90,    91,    92,    93,    94,    96,    97,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   126,   127,   130,   131
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1833 "parser.tab.cc"

