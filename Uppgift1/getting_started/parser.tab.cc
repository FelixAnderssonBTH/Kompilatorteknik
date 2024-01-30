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
      case symbol_kind::S_root: // root
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
      case symbol_kind::S_EXTENDS: // EXTENDS
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
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
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
      case symbol_kind::S_root: // root
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
      case symbol_kind::S_EXTENDS: // EXTENDS
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
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
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
      case symbol_kind::S_root: // root
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
      case symbol_kind::S_EXTENDS: // EXTENDS
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
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
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
      case symbol_kind::S_root: // root
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
      case symbol_kind::S_EXTENDS: // EXTENDS
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
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
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
      case symbol_kind::S_root: // root
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
      case symbol_kind::S_EXTENDS: // EXTENDS
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
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LB: // LB
      case symbol_kind::S_RB: // RB
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
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
  case 2: // root: Expression
#line 31 "parser.yy"
                       {root = yystack_[0].value.as < Node * > ();}
#line 773 "parser.tab.cc"
    break;

  case 3: // Expression: Expression PLUSOP Expression
#line 72 "parser.yy"
                             { yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 779 "parser.tab.cc"
    break;

  case 4: // Expression: Expression MINUSOP Expression
#line 73 "parser.yy"
                                            { yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 785 "parser.tab.cc"
    break;

  case 5: // Expression: Expression MULTOP Expression
#line 74 "parser.yy"
                                           { yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 791 "parser.tab.cc"
    break;

  case 6: // Expression: Expression DIVIDE Expression
#line 75 "parser.yy"
                                           { yylhs.value.as < Node * > () = new Node("DivideExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 797 "parser.tab.cc"
    break;

  case 7: // Expression: Expression AND Expression
#line 76 "parser.yy"
                                        { yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 803 "parser.tab.cc"
    break;

  case 8: // Expression: Expression OR Expression
#line 77 "parser.yy"
                                       { yylhs.value.as < Node * > () = new Node("OrExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 809 "parser.tab.cc"
    break;

  case 9: // Expression: Expression EQUAL Expression
#line 78 "parser.yy"
                                          { yylhs.value.as < Node * > () = new Node("EqualExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 815 "parser.tab.cc"
    break;

  case 10: // Expression: Expression LEFT_ARROW Expression
#line 79 "parser.yy"
                                               { yylhs.value.as < Node * > () = new Node("LeftArrowExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 821 "parser.tab.cc"
    break;

  case 11: // Expression: Expression RIGHT_ARROW Expression
#line 80 "parser.yy"
                                                { yylhs.value.as < Node * > () = new Node("RightArrowExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 827 "parser.tab.cc"
    break;

  case 12: // Expression: Expression LS Expression RS
#line 81 "parser.yy"
                                          { yylhs.value.as < Node * > () = new Node("ArrayExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 833 "parser.tab.cc"
    break;

  case 13: // Expression: Expression DOT Expression LENGHT
#line 82 "parser.yy"
                                               { yylhs.value.as < Node * > () = new Node("LenghtExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());}
#line 839 "parser.tab.cc"
    break;

  case 14: // Expression: Expression DOT Identifier LP Recursive_Expression RP
#line 83 "parser.yy"
                                                                   {yylhs.value.as < Node * > () = new Node("Recursive_Expression", ""); yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 845 "parser.tab.cc"
    break;

  case 15: // Expression: TRUE
#line 84 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("TRUE", "",yylineno);}
#line 851 "parser.tab.cc"
    break;

  case 16: // Expression: FALSE
#line 85 "parser.yy"
                    {yylhs.value.as < Node * > () = new Node("FALSE", "",yylineno);}
#line 857 "parser.tab.cc"
    break;

  case 17: // Expression: THIS
#line 86 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("THIS", "",yylineno);}
#line 863 "parser.tab.cc"
    break;

  case 18: // Expression: NEW INTEGER LS Expression RS
#line 87 "parser.yy"
                                           {yylhs.value.as < Node * > () = new Node("newIntExpression", "",yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 869 "parser.tab.cc"
    break;

  case 19: // Expression: NEW Identifier LP RP
#line 88 "parser.yy"
                                   {yylhs.value.as < Node * > () = new Node("newIdentifierExpression", "",yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());}
#line 875 "parser.tab.cc"
    break;

  case 20: // Expression: NOT Expression
#line 89 "parser.yy"
                             {yylhs.value.as < Node * > () = new Node("NotExpression", "",yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 881 "parser.tab.cc"
    break;

  case 21: // Expression: LP Expression RP
#line 90 "parser.yy"
                               {yylhs.value.as < Node * > () = new Node("BracketsExpression", "",yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 887 "parser.tab.cc"
    break;

  case 22: // Expression: factor
#line 91 "parser.yy"
                          {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r4 ");*/}
#line 893 "parser.tab.cc"
    break;

  case 23: // Expression: Identifier
#line 92 "parser.yy"
                              {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r4 ");*/}
#line 899 "parser.tab.cc"
    break;

  case 24: // Recursive_Expression: Expression
#line 94 "parser.yy"
                                 {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 905 "parser.tab.cc"
    break;

  case 25: // Recursive_Expression: Recursive_Expression COM Expression
#line 95 "parser.yy"
                                      { yylhs.value.as < Node * > () = new Node("Expression", ""); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < std::string > ());}
#line 911 "parser.tab.cc"
    break;

  case 26: // factor: INT
#line 98 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 917 "parser.tab.cc"
    break;

  case 27: // factor: LP Expression RP
#line 99 "parser.yy"
                               { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* printf("r6 ");  simply return the expression */}
#line 923 "parser.tab.cc"
    break;

  case 28: // Identifier: STR
#line 100 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("Str", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 929 "parser.tab.cc"
    break;

  case 29: // Identifier: LP Expression RP
#line 101 "parser.yy"
                               { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* printf("r6 ");  simply return the expression */}
#line 935 "parser.tab.cc"
    break;


#line 939 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -25;

  const signed char parser::yytable_ninf_ = -30;

  const signed char
  parser::yypact_[] =
  {
      92,   -25,    92,   -25,   -25,   -25,   -16,   -25,    92,     4,
     105,   -25,   -25,   105,     3,    92,   -24,    -3,   -25,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    38,   -23,   -21,    47,    64,   -20,   105,   105,   105,
     105,   105,   105,   105,   105,   105,    89,   -25,   -25,   -25,
     -25,    92,   -25,   105,    -4,    92,   -25,   105
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    26,     0,    15,    16,    17,     0,    28,     0,     0,
       2,    22,    23,    20,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,    23,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    29,    19,    12,
      13,     0,    18,    24,     0,     0,    14,    25
  };

  const signed char
  parser::yypgoto_[] =
  {
     -25,   -25,    -2,   -25,   -25,    25
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     9,    10,    54,    11,    12
  };

  const signed char
  parser::yytable_[] =
  {
      13,    19,    55,    14,    18,    20,    17,    30,    32,     0,
      48,   -29,    51,    31,     7,     0,    15,    34,    35,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    56,
      33,    16,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    19,     0,     0,    36,    20,     0,     0,    53,
       0,    19,    49,    57,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
       0,    47,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    50,    19,    52,     1,     0,    20,     0,     2,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    19,
       0,     0,     0,    20,     0,     3,     4,     5,     6,     0,
       0,     0,     7,     0,     8,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29
  };

  const signed char
  parser::yycheck_[] =
  {
       2,     4,     6,    19,     0,     8,     8,     4,    32,    -1,
      33,    32,    32,    15,    30,    -1,    32,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    33,
      33,     6,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     4,    -1,    -1,    20,     8,    -1,    -1,    51,
      -1,     4,     5,    55,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      -1,    33,     8,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    28,     4,     5,     3,    -1,     8,    -1,     7,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     4,
      -1,    -1,    -1,     8,    -1,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    32,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     7,    23,    24,    25,    26,    30,    32,    46,
      47,    49,    50,    47,    19,    32,    50,    47,     0,     4,
       8,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       4,    47,    32,    33,    47,    47,    50,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    33,    33,     5,
      28,    32,     5,    47,    48,     6,    33,    47
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    46,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    48,    48,    49,    49,    50,    50
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     6,     1,     1,     1,     5,     4,
       2,     3,     1,     1,     1,     3,     1,     3,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INT", "LS", "RS",
  "COM", "NOT", "DOT", "EUQUAL_SIGN", "SEMI", "CLASS", "EXTENDS", "PUBLIC",
  "VOID", "STATIC", "MAIN", "STRING", "BOOL", "INTEGER", "IF", "ELSE",
  "WHILE", "TRUE", "FALSE", "THIS", "NEW", "RETURN", "LENGHT", "PRINT",
  "STR", "ID", "LP", "RP", "LB", "RB", "PLUSOP", "MINUSOP", "MULTOP",
  "DIVIDE", "AND", "OR", "EQUAL", "LEFT_ARROW", "RIGHT_ARROW", "$accept",
  "root", "Expression", "Recursive_Expression", "factor", "Identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  parser::yyrline_[] =
  {
       0,    31,    31,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    94,    95,    98,    99,   100,   101
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
#line 1448 "parser.tab.cc"

