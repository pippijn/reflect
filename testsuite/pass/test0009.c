typedef struct pt_print_visitor self_type;

struct pt_print_visitor
{
  struct pt_visitor base;

  struct xmlDocPtr doc;
  struct xmlNodePtr cur;
  struct FILE *fh;
};

static struct xmlChar const *
itoa (int n)
{
  static char buf[12];
  snprintf (buf, sizeof buf, "%d", n);
  return buf;
}

static void
pt_print_visitor_visit_add (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "add", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_add_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_add_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_add_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_add_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "add_assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_add_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_add_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_add_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_address_of (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "address_of", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_address_of_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_address_of_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_alignof_type (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "alignof_type", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "alignof_tok", NULL);
    pt_node_accept (pt_alignof_type_alignof_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_alignof_type_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "type", NULL);
    pt_node_accept (pt_alignof_type_type (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_alignof_type_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_alignof_var (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "alignof_var", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "alignof_tok", NULL);
    pt_node_accept (pt_alignof_var_alignof_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_alignof_var_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_and_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "and_assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_and_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_and_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_and_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_any_word115 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "any_word115", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_any_word115_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_any_word116 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "any_word116", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_any_word116_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_any_word117 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "any_word117", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_any_word117_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_argument_expression_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "argument_expression_list", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_argument_expression_list_prev (node) != NULL)
      pt_node_accept (pt_argument_expression_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    if (pt_argument_expression_list_comma (node) != NULL)
      pt_node_accept (pt_argument_expression_list_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_argument_expression_list_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_array_abstract_declarator (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "array_abstract_declarator", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lsqbrack", NULL);
    pt_node_accept (pt_array_abstract_declarator_lsqbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    if (pt_array_abstract_declarator_expr (node) != NULL)
      pt_node_accept (pt_array_abstract_declarator_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rsqbrack", NULL);
    pt_node_accept (pt_array_abstract_declarator_rsqbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_array_abstract_declarator_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "array_abstract_declarator_list", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_array_abstract_declarator_list_prev (node) != NULL)
      pt_node_accept (pt_array_abstract_declarator_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decl", NULL);
    pt_node_accept (pt_array_abstract_declarator_list_decl (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_array_access (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "array_access", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_array_access_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lsqbrack", NULL);
    pt_node_accept (pt_array_access_lsqbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_array_access_rhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rsqbrack", NULL);
    pt_node_accept (pt_array_access_rsqbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_array_labelled_initialised (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "array_labelled_initialised", NULL);
  xmlNewProp (self->cur, "members", itoa (7));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lsqbrack", NULL);
    pt_node_accept (pt_array_labelled_initialised_lsqbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_array_labelled_initialised_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "dots", NULL);
    if (pt_array_labelled_initialised_dots (node) != NULL)
      pt_node_accept (pt_array_labelled_initialised_dots (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr2", NULL);
    if (pt_array_labelled_initialised_expr2 (node) != NULL)
      pt_node_accept (pt_array_labelled_initialised_expr2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "equals", NULL);
    pt_node_accept (pt_array_labelled_initialised_equals (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rsqbrack", NULL);
    pt_node_accept (pt_array_labelled_initialised_rsqbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "init", NULL);
    if (pt_array_labelled_initialised_init (node) != NULL)
      pt_node_accept (pt_array_labelled_initialised_init (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_asm361 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "asm361", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_asm361_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_asm361_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_asm361_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_asm361_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_asm_argument (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "asm_argument", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "target", NULL);
    pt_node_accept (pt_asm_argument_target (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_asm_argument_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_asm_argument_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_asm_argument_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_asm_argument_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "asm_argument_list", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_asm_argument_list_prev (node) != NULL)
      pt_node_accept (pt_asm_argument_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    if (pt_asm_argument_list_comma (node) != NULL)
      pt_node_accept (pt_asm_argument_list_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "arg", NULL);
    pt_node_accept (pt_asm_argument_list_arg (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_asm_argument_list_opt362 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "asm_argument_list_opt362", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_asm_argument_list_opt362_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_asm_clobbered_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "asm_clobbered_list", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_asm_clobbered_list_prev (node) != NULL)
      pt_node_accept (pt_asm_clobbered_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    if (pt_asm_clobbered_list_comma (node) != NULL)
      pt_node_accept (pt_asm_clobbered_list_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "clobber", NULL);
    pt_node_accept (pt_asm_clobbered_list_clobber (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_asm_opt359 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "asm_opt359", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_asm_opt359_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_asm_opt360 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "asm_opt360", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_asm_opt360_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_asm_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "asm_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (12));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "asm_tok", NULL);
    pt_node_accept (pt_asm_statement_asm_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "tquals", NULL);
    pt_node_accept (pt_asm_statement_tquals (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_asm_statement_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "code", NULL);
    pt_node_accept (pt_asm_statement_code (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "in_arg_colon", NULL);
    if (pt_asm_statement_in_arg_colon (node) != NULL)
      pt_node_accept (pt_asm_statement_in_arg_colon (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "in_args", NULL);
    if (pt_asm_statement_in_args (node) != NULL)
      pt_node_accept (pt_asm_statement_in_args (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "out_arg_colon", NULL);
    if (pt_asm_statement_out_arg_colon (node) != NULL)
      pt_node_accept (pt_asm_statement_out_arg_colon (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "out_args", NULL);
    if (pt_asm_statement_out_args (node) != NULL)
      pt_node_accept (pt_asm_statement_out_args (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "clobber_colon", NULL);
    if (pt_asm_statement_clobber_colon (node) != NULL)
      pt_node_accept (pt_asm_statement_clobber_colon (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "clobbers", NULL);
    if (pt_asm_statement_clobbers (node) != NULL)
      pt_node_accept (pt_asm_statement_clobbers (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_asm_statement_rbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_asm_statement_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attrib375 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attrib375", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_attrib375_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attrib376 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attrib376", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "name", NULL);
    pt_node_accept (pt_attrib376_name (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attrib377 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attrib377", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "name", NULL);
    pt_node_accept (pt_attrib377_name (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_attrib377_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "id", NULL);
    pt_node_accept (pt_attrib377_id (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_attrib377_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attrib378 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attrib378", NULL);
  xmlNewProp (self->cur, "members", itoa (6));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "name", NULL);
    pt_node_accept (pt_attrib378_name (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_attrib378_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "id", NULL);
    pt_node_accept (pt_attrib378_id (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    pt_node_accept (pt_attrib378_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_attrib378_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_attrib378_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attrib379 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attrib379", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "name", NULL);
    pt_node_accept (pt_attrib379_name (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_attrib379_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_attrib379_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_attrib379_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attribute (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attribute", NULL);
  xmlNewProp (self->cur, "members", itoa (6));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "attribute_tok", NULL);
    pt_node_accept (pt_attribute_attribute_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack1", NULL);
    pt_node_accept (pt_attribute_lbrack1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack2", NULL);
    pt_node_accept (pt_attribute_lbrack2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "attributes", NULL);
    pt_node_accept (pt_attribute_attributes (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack1", NULL);
    pt_node_accept (pt_attribute_rbrack1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack2", NULL);
    pt_node_accept (pt_attribute_rbrack2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attribute_list373 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attribute_list373", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "attrib", NULL);
    pt_node_accept (pt_attribute_list373_attrib (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attribute_list374 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attribute_list374", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    pt_node_accept (pt_attribute_list374_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    pt_node_accept (pt_attribute_list374_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "attrib", NULL);
    pt_node_accept (pt_attribute_list374_attrib (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attributes370 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attributes370", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_attributes370_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attributes371 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attributes371", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_attributes371_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_attributes371_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attributes_opt368 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attributes_opt368", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_attributes_opt368_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_attributes_opt369 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "attributes_opt369", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_attributes_opt369_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_auto_str_class_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "auto_str_class_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "auto_tok", NULL);
    pt_node_accept (pt_auto_str_class_spec_auto_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_basic_declaration_specifier21 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "basic_declaration_specifier21", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_basic_declaration_specifier21_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_basic_declaration_specifier21_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_basic_declaration_specifier22 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "basic_declaration_specifier22", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_basic_declaration_specifier22_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_basic_declaration_specifier22_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_basic_declaration_specifier23 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "basic_declaration_specifier23", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_basic_declaration_specifier23_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_basic_declaration_specifier23_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_basic_declaration_specifier24 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "basic_declaration_specifier24", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_basic_declaration_specifier24_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_basic_declaration_specifier24_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_basic_type_specifier41 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "basic_type_specifier41", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    if (pt_basic_type_specifier41_n1 (node) != NULL)
      pt_node_accept (pt_basic_type_specifier41_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_basic_type_specifier41_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_basic_type_specifier42 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "basic_type_specifier42", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_basic_type_specifier42_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_basic_type_specifier42_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_basic_type_specifier43 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "basic_type_specifier43", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_basic_type_specifier43_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_basic_type_specifier43_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_bit_field_size (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "bit_field_size", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "colon", NULL);
    pt_node_accept (pt_bit_field_size_colon (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_bit_field_size_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_bit_field_size_opt330 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "bit_field_size_opt330", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_bit_field_size_opt330_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_bit_field_size_opt331 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "bit_field_size_opt331", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "bitfield", NULL);
    pt_node_accept (pt_bit_field_size_opt331_bitfield (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_bitwise_and (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "bitwise_and", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_bitwise_and_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_bitwise_and_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_bitwise_and_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_bitwise_negate (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "bitwise_negate", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_bitwise_negate_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_bitwise_negate_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_bitwise_or (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "bitwise_or", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_bitwise_or_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_bitwise_or_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_bitwise_or_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_bitwise_xor (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "bitwise_xor", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_bitwise_xor_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_bitwise_xor_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_bitwise_xor_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_brace_expression (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "brace_expression", NULL);
  xmlNewProp (self->cur, "members", itoa (6));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_brace_expression_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrace", NULL);
    pt_node_accept (pt_brace_expression_lbrace (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decls", NULL);
    if (pt_brace_expression_decls (node) != NULL)
      pt_node_accept (pt_brace_expression_decls (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "stmts", NULL);
    pt_node_accept (pt_brace_expression_stmts (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrace", NULL);
    pt_node_accept (pt_brace_expression_rbrace (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_brace_expression_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_bracket_expression (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "bracket_expression", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_bracket_expression_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_bracket_expression_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_bracket_expression_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_bracketed_initialiser_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "bracketed_initialiser_list", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_bracketed_initialiser_list_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "list", NULL);
    if (pt_bracketed_initialiser_list_list (node) != NULL)
      pt_node_accept (pt_bracketed_initialiser_list_list (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    if (pt_bracketed_initialiser_list_comma (node) != NULL)
      pt_node_accept (pt_bracketed_initialiser_list_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_bracketed_initialiser_list_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_break_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "break_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "break_tok", NULL);
    pt_node_accept (pt_break_statement_break_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_break_statement_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_case_label_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "case_label_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "case_tok", NULL);
    pt_node_accept (pt_case_label_statement_case_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_case_label_statement_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_case_label_statement_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_char_constant (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "char_constant", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "token", NULL);
    pt_node_accept (pt_char_constant_token (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_char_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "char_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "char_tok", NULL);
    pt_node_accept (pt_char_type_spec_char_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_clean_postfix_typedef_declarator76 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "clean_postfix_typedef_declarator76", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_clean_postfix_typedef_declarator76_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_clean_postfix_typedef_declarator76_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_clean_postfix_typedef_declarator76_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_clean_postfix_typedef_declarator77 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "clean_postfix_typedef_declarator77", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_clean_postfix_typedef_declarator77_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_clean_postfix_typedef_declarator77_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_clean_postfix_typedef_declarator77_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_clean_postfix_typedef_declarator77_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_clean_typedef_declarator73 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "clean_typedef_declarator73", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_clean_typedef_declarator73_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_clean_typedef_declarator74 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "clean_typedef_declarator74", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_clean_typedef_declarator74_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_clean_typedef_declarator74_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_clean_typedef_declarator74_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_clean_typedef_declarator75 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "clean_typedef_declarator75", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_clean_typedef_declarator75_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_clean_typedef_declarator75_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_clean_typedef_declarator75_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_clean_typedef_declarator75_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_comma_expression (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "comma_expression", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    pt_node_accept (pt_comma_expression_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    pt_node_accept (pt_comma_expression_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_comma_expression_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_comma_opt340 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "comma_opt340", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_comma_opt340_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_comma_opt341 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "comma_opt341", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    pt_node_accept (pt_comma_opt341_comma (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_complex_type_qualifier (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "complex_type_qualifier", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_complex_type_qualifier_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_compound_literal (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "compound_literal", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_compound_literal_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "type", NULL);
    pt_node_accept (pt_compound_literal_type (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_compound_literal_rbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "init_list", NULL);
    pt_node_accept (pt_compound_literal_init_list (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_compound_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "compound_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrace", NULL);
    pt_node_accept (pt_compound_statement_lbrace (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decls", NULL);
    if (pt_compound_statement_decls (node) != NULL)
      pt_node_accept (pt_compound_statement_decls (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "stmts", NULL);
    if (pt_compound_statement_stmts (node) != NULL)
      pt_node_accept (pt_compound_statement_stmts (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrace", NULL);
    pt_node_accept (pt_compound_statement_rbrace (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_const_type_qualifier (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "const_type_qualifier", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "const_tok", NULL);
    pt_node_accept (pt_const_type_qualifier_const_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_continue_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "continue_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "continue_tok", NULL);
    pt_node_accept (pt_continue_statement_continue_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_continue_statement_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration1 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration1", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration1_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration1_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration2 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration2", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration2_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration2_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration3 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration3", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration3_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration3_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration4 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration4", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration4_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration4_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration5 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration5", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration5_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration5_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_declaration5_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration6 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration6", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration6_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration6_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_declaration6_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_declaration6_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration7 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration7", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration7_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration7_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_declaration7_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration8 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration8", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration8_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration8_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_declaration8_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_declaration8_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration_list", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_declaration_list_prev (node) != NULL)
      pt_node_accept (pt_declaration_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decl", NULL);
    pt_node_accept (pt_declaration_list_decl (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration_qualifier_list31 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration_qualifier_list31", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration_qualifier_list31_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration_qualifier_list31_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration_qualifier_list32 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration_qualifier_list32", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration_qualifier_list32_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration_qualifier_list32_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_declaration_qualifier_list32_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_declaration_qualifier_list32_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaration_qualifier_list33 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaration_qualifier_list33", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaration_qualifier_list33_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaration_qualifier_list33_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declarator384 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declarator384", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declarator384_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declarator384_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaring_list10 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaring_list10", NULL);
  xmlNewProp (self->cur, "members", itoa (6));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaring_list10_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaring_list10_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_declaring_list10_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_declaring_list10_n4 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n5", NULL);
    pt_node_accept (pt_declaring_list10_n5 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n6", NULL);
    pt_node_accept (pt_declaring_list10_n6 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaring_list11 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaring_list11", NULL);
  xmlNewProp (self->cur, "members", itoa (5));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaring_list11_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaring_list11_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_declaring_list11_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_declaring_list11_n4 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n5", NULL);
    pt_node_accept (pt_declaring_list11_n5 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaring_list12 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaring_list12", NULL);
  xmlNewProp (self->cur, "members", itoa (6));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaring_list12_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaring_list12_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_declaring_list12_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_declaring_list12_n4 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n5", NULL);
    pt_node_accept (pt_declaring_list12_n5 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n6", NULL);
    pt_node_accept (pt_declaring_list12_n6 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaring_list13 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaring_list13", NULL);
  xmlNewProp (self->cur, "members", itoa (6));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaring_list13_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaring_list13_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_declaring_list13_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_declaring_list13_n4 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n5", NULL);
    pt_node_accept (pt_declaring_list13_n5 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n6", NULL);
    pt_node_accept (pt_declaring_list13_n6 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_declaring_list9 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "declaring_list9", NULL);
  xmlNewProp (self->cur, "members", itoa (5));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_declaring_list9_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_declaring_list9_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_declaring_list9_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_declaring_list9_n4 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n5", NULL);
    pt_node_accept (pt_declaring_list9_n5 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_default_declaring_list14 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "default_declaring_list14", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_default_declaring_list14_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_default_declaring_list14_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_default_declaring_list14_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_default_declaring_list14_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_default_declaring_list15 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "default_declaring_list15", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_default_declaring_list15_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_default_declaring_list15_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_default_declaring_list15_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_default_declaring_list15_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_default_declaring_list16 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "default_declaring_list16", NULL);
  xmlNewProp (self->cur, "members", itoa (5));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_default_declaring_list16_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_default_declaring_list16_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_default_declaring_list16_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_default_declaring_list16_n4 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n5", NULL);
    pt_node_accept (pt_default_declaring_list16_n5 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_default_int (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "default_int", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_default_int_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_default_label_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "default_label_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "default_tok", NULL);
    pt_node_accept (pt_default_label_statement_default_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_default_label_statement_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_designated_initialiser (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "designated_initialiser", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "dot", NULL);
    pt_node_accept (pt_designated_initialiser_dot (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "id", NULL);
    pt_node_accept (pt_designated_initialiser_id (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "equals", NULL);
    pt_node_accept (pt_designated_initialiser_equals (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "init", NULL);
    pt_node_accept (pt_designated_initialiser_init (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_divide (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "divide", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_divide_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_divide_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_divide_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_divide_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "divide_assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_divide_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_divide_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_divide_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_do_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "do_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (7));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "do_tok", NULL);
    pt_node_accept (pt_do_statement_do_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "stmt", NULL);
    pt_node_accept (pt_do_statement_stmt (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "while_tok", NULL);
    pt_node_accept (pt_do_statement_while_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_do_statement_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "cond", NULL);
    pt_node_accept (pt_do_statement_cond (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_do_statement_rbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_do_statement_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_double_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "double_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "double_tok", NULL);
    pt_node_accept (pt_double_type_spec_double_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_enum_specifier (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "enum_specifier", NULL);
  xmlNewProp (self->cur, "members", itoa (6));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "enum_tok", NULL);
    pt_node_accept (pt_enum_specifier_enum_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "tag", NULL);
    if (pt_enum_specifier_tag (node) != NULL)
      pt_node_accept (pt_enum_specifier_tag (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrace", NULL);
    if (pt_enum_specifier_lbrace (node) != NULL)
      pt_node_accept (pt_enum_specifier_lbrace (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "values", NULL);
    if (pt_enum_specifier_values (node) != NULL)
      pt_node_accept (pt_enum_specifier_values (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    if (pt_enum_specifier_comma (node) != NULL)
      pt_node_accept (pt_enum_specifier_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrace", NULL);
    if (pt_enum_specifier_rbrace (node) != NULL)
      pt_node_accept (pt_enum_specifier_rbrace (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_enumerator_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "enumerator_list", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_enumerator_list_prev (node) != NULL)
      pt_node_accept (pt_enumerator_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    if (pt_enumerator_list_comma (node) != NULL)
      pt_node_accept (pt_enumerator_list_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "id", NULL);
    pt_node_accept (pt_enumerator_list_id (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "value", NULL);
    pt_node_accept (pt_enumerator_list_value (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_enumerator_value_opt338 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "enumerator_value_opt338", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_enumerator_value_opt338_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_enumerator_value_opt339 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "enumerator_value_opt339", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "equals", NULL);
    pt_node_accept (pt_enumerator_value_opt339_equals (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_enumerator_value_opt339_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_equals (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "equals", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_equals_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_equals_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_equals_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_expression_opt250 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "expression_opt250", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_expression_opt250_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_expression_opt254 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "expression_opt254", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_expression_opt254_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_expression_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "expression_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_expression_statement_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_expression_statement_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_extern_str_class_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "extern_str_class_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "extern_tok", NULL);
    pt_node_accept (pt_extern_str_class_spec_extern_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_external_definition385 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "external_definition385", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_external_definition385_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_external_definition385_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_float_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "float_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "float_tok", NULL);
    pt_node_accept (pt_float_type_spec_float_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_floating_constant (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "floating_constant", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "token", NULL);
    pt_node_accept (pt_floating_constant_token (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_for_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "for_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (9));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "for_tok", NULL);
    pt_node_accept (pt_for_statement_for_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_for_statement_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "init", NULL);
    pt_node_accept (pt_for_statement_init (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "init_semi", NULL);
    pt_node_accept (pt_for_statement_init_semi (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "cond", NULL);
    pt_node_accept (pt_for_statement_cond (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "cond_semi", NULL);
    pt_node_accept (pt_for_statement_cond_semi (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "inc", NULL);
    pt_node_accept (pt_for_statement_inc (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_for_statement_rbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "stmt", NULL);
    pt_node_accept (pt_for_statement_stmt (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_fullold_function_declarator (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "fullold_function_declarator", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "declarator", NULL);
    pt_node_accept (pt_fullold_function_declarator_declarator (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decls", NULL);
    if (pt_fullold_function_declarator_decls (node) != NULL)
      pt_node_accept (pt_fullold_function_declarator_decls (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_function_call (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "function_call", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_function_call_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_function_call_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "args", NULL);
    if (pt_function_call_args (node) != NULL)
      pt_node_accept (pt_function_call_args (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_function_call_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_function_definition (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "function_definition", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "declarator", NULL);
    pt_node_accept (pt_function_definition_declarator (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "body", NULL);
    pt_node_accept (pt_function_definition_body (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_function_definition_dqual (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "function_definition_dqual", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "dqual", NULL);
    pt_node_accept (pt_function_definition_dqual_dqual (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "declarator", NULL);
    pt_node_accept (pt_function_definition_dqual_declarator (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "body", NULL);
    pt_node_accept (pt_function_definition_dqual_body (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_function_definition_tqual (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "function_definition_tqual", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "tqual", NULL);
    pt_node_accept (pt_function_definition_tqual_tqual (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "declarator", NULL);
    pt_node_accept (pt_function_definition_tqual_declarator (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "body", NULL);
    pt_node_accept (pt_function_definition_tqual_body (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_gcc_extension386 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "gcc_extension386", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_gcc_extension386_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_goto_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "goto_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "goto_tok", NULL);
    pt_node_accept (pt_goto_statement_goto_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "label", NULL);
    pt_node_accept (pt_goto_statement_label (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_goto_statement_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_greater_than (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "greater_than", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_greater_than_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_greater_than_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_greater_than_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_greater_than_equals (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "greater_than_equals", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_greater_than_equals_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_greater_than_equals_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_greater_than_equals_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_hex_constant (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "hex_constant", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "token", NULL);
    pt_node_accept (pt_hex_constant_token (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_identifier_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "identifier_list", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_identifier_list_prev (node) != NULL)
      pt_node_accept (pt_identifier_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    if (pt_identifier_list_comma (node) != NULL)
      pt_node_accept (pt_identifier_list_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "id", NULL);
    pt_node_accept (pt_identifier_list_id (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_if_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "if_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (7));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "if_tok", NULL);
    pt_node_accept (pt_if_statement_if_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_if_statement_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "cond", NULL);
    pt_node_accept (pt_if_statement_cond (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_if_statement_rbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "then_stmt", NULL);
    pt_node_accept (pt_if_statement_then_stmt (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "else_tok", NULL);
    if (pt_if_statement_else_tok (node) != NULL)
      pt_node_accept (pt_if_statement_else_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "else_stmt", NULL);
    if (pt_if_statement_else_stmt (node) != NULL)
      pt_node_accept (pt_if_statement_else_stmt (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_imag_expression (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "imag_expression", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_imag_expression_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_imag_expression_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_initialiser121 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "initialiser121", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_initialiser121_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_initialiser121_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_initialiser121_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_initialiser_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "initialiser_list", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_initialiser_list_prev (node) != NULL)
      pt_node_accept (pt_initialiser_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    if (pt_initialiser_list_comma (node) != NULL)
      pt_node_accept (pt_initialiser_list_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "init", NULL);
    pt_node_accept (pt_initialiser_list_init (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_initialiser_opt118 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "initialiser_opt118", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_initialiser_opt118_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_initialiser_opt119 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "initialiser_opt119", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_initialiser_opt119_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_initialiser_opt119_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_inline_type_qualifier (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "inline_type_qualifier", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_inline_type_qualifier_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_int_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "int_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "int_tok", NULL);
    pt_node_accept (pt_int_type_spec_int_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_integer_constant (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "integer_constant", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "token", NULL);
    pt_node_accept (pt_integer_constant_token (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_label_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "label_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "label", NULL);
    pt_node_accept (pt_label_statement_label (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_label_statement_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_left_shift_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "left_shift_assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_left_shift_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_left_shift_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_left_shift_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_less_than (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "less_than", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_less_than_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_less_than_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_less_than_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_less_than_equals (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "less_than_equals", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_less_than_equals_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_less_than_equals_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_less_than_equals_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_logical_and (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "logical_and", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_logical_and_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_logical_and_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_logical_and_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_logical_not (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "logical_not", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_logical_not_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_logical_not_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_logical_or (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "logical_or", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_logical_or_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_logical_or_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_logical_or_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_long_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "long_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "long_tok", NULL);
    pt_node_accept (pt_long_type_spec_long_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_modulo (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "modulo", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_modulo_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_modulo_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_modulo_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_modulo_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "modulo_assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_modulo_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_modulo_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_modulo_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_multiply (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "multiply", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_multiply_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_multiply_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_multiply_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_multiply_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "multiply_assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_multiply_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_multiply_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_multiply_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_negate (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "negate", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_negate_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_negate_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_not_equals (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "not_equals", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_not_equals_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_not_equals_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_not_equals_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_octal_constant (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "octal_constant", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "token", NULL);
    pt_node_accept (pt_octal_constant_token (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_old_function_declarator102 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "old_function_declarator102", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_old_function_declarator102_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_old_function_declarator103 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "old_function_declarator103", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_old_function_declarator103_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_old_function_declarator103_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    if (pt_old_function_declarator103_n3 (node) != NULL)
      pt_node_accept (pt_old_function_declarator103_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_old_function_declarator103_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_old_function_definition_dspec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "old_function_definition_dspec", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "dspec", NULL);
    pt_node_accept (pt_old_function_definition_dspec_dspec (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "declarator", NULL);
    pt_node_accept (pt_old_function_definition_dspec_declarator (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "body", NULL);
    pt_node_accept (pt_old_function_definition_dspec_body (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_old_function_definition_tspec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "old_function_definition_tspec", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "tspec", NULL);
    pt_node_accept (pt_old_function_definition_tspec_tspec (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "declarator", NULL);
    pt_node_accept (pt_old_function_definition_tspec_declarator (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "body", NULL);
    pt_node_accept (pt_old_function_definition_tspec_body (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_or_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "or_assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_or_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_or_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_or_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration139 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration139", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_declaration139_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_parameter_declaration139_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration140 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration140", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_declaration140_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_parameter_declaration140_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_parameter_declaration140_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration141 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration141", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_declaration141_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_parameter_declaration141_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_parameter_declaration141_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration142 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration142", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_declaration142_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_parameter_declaration142_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_parameter_declaration142_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration143 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration143", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_declaration143_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_parameter_declaration143_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration144 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration144", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_declaration144_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_parameter_declaration144_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_parameter_declaration144_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration145 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration145", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_declaration145_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_parameter_declaration145_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_parameter_declaration145_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_parameter_declaration145_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration146 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration146", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_declaration146_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_parameter_declaration146_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_parameter_declaration146_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration156 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration156", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "attrs", NULL);
    pt_node_accept (pt_parameter_declaration156_attrs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "quals", NULL);
    pt_node_accept (pt_parameter_declaration156_quals (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "defint", NULL);
    pt_node_accept (pt_parameter_declaration156_defint (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration157 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration157", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "attrs", NULL);
    pt_node_accept (pt_parameter_declaration157_attrs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "quals", NULL);
    pt_node_accept (pt_parameter_declaration157_quals (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "defint", NULL);
    pt_node_accept (pt_parameter_declaration157_defint (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decl", NULL);
    pt_node_accept (pt_parameter_declaration157_decl (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_declaration158 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_declaration158", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "attrs", NULL);
    pt_node_accept (pt_parameter_declaration158_attrs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "quals", NULL);
    pt_node_accept (pt_parameter_declaration158_quals (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "defint", NULL);
    pt_node_accept (pt_parameter_declaration158_defint (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decl", NULL);
    pt_node_accept (pt_parameter_declaration158_decl (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_list", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_parameter_list_prev (node) != NULL)
      pt_node_accept (pt_parameter_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    if (pt_parameter_list_comma (node) != NULL)
      pt_node_accept (pt_parameter_list_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "param", NULL);
    pt_node_accept (pt_parameter_list_param (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_type_list135 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_type_list135", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_type_list135_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    if (pt_parameter_type_list135_n2 (node) != NULL)
      pt_node_accept (pt_parameter_type_list135_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    if (pt_parameter_type_list135_n3 (node) != NULL)
      pt_node_accept (pt_parameter_type_list135_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_typedef_declarator70 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_typedef_declarator70", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_typedef_declarator70_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_typedef_declarator71 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_typedef_declarator71", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_typedef_declarator71_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_parameter_typedef_declarator71_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_parameter_typedef_declarator72 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "parameter_typedef_declarator72", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_parameter_typedef_declarator72_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_paren_identifier_declarator100 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "paren_identifier_declarator100", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_paren_identifier_declarator100_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_paren_identifier_declarator101 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "paren_identifier_declarator101", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_paren_identifier_declarator101_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_paren_identifier_declarator101_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_paren_identifier_declarator101_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_paren_postfix_typedef_declarator65 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "paren_postfix_typedef_declarator65", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator65_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator65_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator65_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_paren_postfix_typedef_declarator66 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "paren_postfix_typedef_declarator66", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator66_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator66_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator66_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator66_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_paren_postfix_typedef_declarator67 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "paren_postfix_typedef_declarator67", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator67_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator67_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator67_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_paren_postfix_typedef_declarator67_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_paren_typedef_declarator60 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "paren_typedef_declarator60", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_paren_typedef_declarator60_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_paren_typedef_declarator61 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "paren_typedef_declarator61", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_paren_typedef_declarator61_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_paren_typedef_declarator61_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_paren_typedef_declarator61_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_paren_typedef_declarator62 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "paren_typedef_declarator62", NULL);
  xmlNewProp (self->cur, "members", itoa (5));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_paren_typedef_declarator62_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_paren_typedef_declarator62_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_paren_typedef_declarator62_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_paren_typedef_declarator62_n4 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n5", NULL);
    pt_node_accept (pt_paren_typedef_declarator62_n5 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_paren_typedef_declarator63 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "paren_typedef_declarator63", NULL);
  xmlNewProp (self->cur, "members", itoa (6));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_paren_typedef_declarator63_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_paren_typedef_declarator63_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_paren_typedef_declarator63_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_paren_typedef_declarator63_n4 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n5", NULL);
    pt_node_accept (pt_paren_typedef_declarator63_n5 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n6", NULL);
    pt_node_accept (pt_paren_typedef_declarator63_n6 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_paren_typedef_declarator64 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "paren_typedef_declarator64", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_paren_typedef_declarator64_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_paren_typedef_declarator64_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_paren_typedef_declarator64_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_paren_typedef_declarator64_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_pointer (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "pointer", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_pointer_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_pointer_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    if (pt_pointer_n3 (node) != NULL)
      pt_node_accept (pt_pointer_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    if (pt_pointer_n4 (node) != NULL)
      pt_node_accept (pt_pointer_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_pointer_access (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "pointer_access", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_pointer_access_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_pointer_access_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "member", NULL);
    pt_node_accept (pt_pointer_access_member (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_pointer_dereference (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "pointer_dereference", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_pointer_dereference_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_pointer_dereference_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_pointer_type_qualifier_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "pointer_type_qualifier_list", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_pointer_type_qualifier_list_prev (node) != NULL)
      pt_node_accept (pt_pointer_type_qualifier_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "qual", NULL);
    pt_node_accept (pt_pointer_type_qualifier_list_qual (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_positive (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "positive", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_positive_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_positive_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_post_decrement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "post_decrement", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_post_decrement_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_post_decrement_op (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_post_increment (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "post_increment", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_post_increment_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_post_increment_op (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfix_abstract_declarator85 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfix_abstract_declarator85", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_postfix_abstract_declarator85_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_postfix_abstract_declarator85_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_postfix_abstract_declarator85_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfix_abstract_declarator86 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfix_abstract_declarator86", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_postfix_abstract_declarator86_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_postfix_abstract_declarator86_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_postfix_abstract_declarator86_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfix_abstract_declarator87 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfix_abstract_declarator87", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_postfix_abstract_declarator87_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_postfix_abstract_declarator87_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_postfix_abstract_declarator87_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfix_abstract_declarator88 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfix_abstract_declarator88", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_postfix_abstract_declarator88_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_postfix_abstract_declarator88_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_postfix_abstract_declarator88_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_postfix_abstract_declarator88_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfix_identifier_declarator97 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfix_identifier_declarator97", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_postfix_identifier_declarator97_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_postfix_identifier_declarator97_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfix_identifier_declarator98 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfix_identifier_declarator98", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_postfix_identifier_declarator98_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_postfix_identifier_declarator98_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_postfix_identifier_declarator98_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfix_identifier_declarator99 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfix_identifier_declarator99", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_postfix_identifier_declarator99_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_postfix_identifier_declarator99_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_postfix_identifier_declarator99_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_postfix_identifier_declarator99_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfix_old_function_declarator105 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfix_old_function_declarator105", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_postfix_old_function_declarator105_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_postfix_old_function_declarator105_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_postfix_old_function_declarator105_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_postfix_old_function_declarator105_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfix_old_function_declarator106 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfix_old_function_declarator106", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_postfix_old_function_declarator106_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_postfix_old_function_declarator106_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_postfix_old_function_declarator106_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    if (pt_postfix_old_function_declarator106_n4 (node) != NULL)
      pt_node_accept (pt_postfix_old_function_declarator106_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfixing_abstract_declarator89 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfixing_abstract_declarator89", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_postfixing_abstract_declarator89_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_postfixing_abstract_declarator90 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "postfixing_abstract_declarator90", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_postfixing_abstract_declarator90_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "params", NULL);
    if (pt_postfixing_abstract_declarator90_params (node) != NULL)
      pt_node_accept (pt_postfixing_abstract_declarator90_params (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_postfixing_abstract_declarator90_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_pre_decrement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "pre_decrement", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_pre_decrement_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_pre_decrement_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_pre_increment (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "pre_increment", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_pre_increment_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_pre_increment_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_qualifier_list159 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "qualifier_list159", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_qualifier_list159_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_qualifier_list160 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "qualifier_list160", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_qualifier_list160_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_real_expression (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "real_expression", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_real_expression_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_real_expression_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_register_str_class_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "register_str_class_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "register_tok", NULL);
    pt_node_accept (pt_register_str_class_spec_register_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_restrict_pointer_type_qualifier (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "restrict_pointer_type_qualifier", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_restrict_pointer_type_qualifier_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_restrict_type_qualifier (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "restrict_type_qualifier", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_restrict_type_qualifier_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_return_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "return_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "return_tok", NULL);
    pt_node_accept (pt_return_statement_return_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_return_statement_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_return_statement_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_right_shift_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "right_shift_assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_right_shift_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_right_shift_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_right_shift_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_shift_left (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "shift_left", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_shift_left_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_shift_left_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_shift_left_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_shift_right (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "shift_right", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_shift_right_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_shift_right_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_shift_right_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_short_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "short_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "short_tok", NULL);
    pt_node_accept (pt_short_type_spec_short_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_signer_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "signer_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "signed_tok", NULL);
    pt_node_accept (pt_signer_type_spec_signed_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_simple_paren_typedef_declarator68 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "simple_paren_typedef_declarator68", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_simple_paren_typedef_declarator68_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_simple_paren_typedef_declarator69 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "simple_paren_typedef_declarator69", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_simple_paren_typedef_declarator69_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_simple_paren_typedef_declarator69_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_simple_paren_typedef_declarator69_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_sizeof_type (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "sizeof_type", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_sizeof_type_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_sizeof_type_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_sizeof_type_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_sizeof_type_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_sizeof_var (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "sizeof_var", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_sizeof_var_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_sizeof_var_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_statement350 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "statement350", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_statement350_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_statement_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "statement_list", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_statement_list_prev (node) != NULL)
      pt_node_accept (pt_statement_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "stmt", NULL);
    pt_node_accept (pt_statement_list_stmt (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_static_str_class_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "static_str_class_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "static_tok", NULL);
    pt_node_accept (pt_static_str_class_spec_static_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_string_literal_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "string_literal_list", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_string_literal_list_prev (node) != NULL)
      pt_node_accept (pt_string_literal_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "string", NULL);
    pt_node_accept (pt_string_literal_list_string (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "struct_tok", NULL);
    pt_node_accept (pt_struct_struct_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_access (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_access", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_struct_access_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_struct_access_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "member", NULL);
    pt_node_accept (pt_struct_access_member (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_declaration321 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_declaration321", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_struct_declaration321_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_struct_declaration321_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_declaration322 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_declaration322", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_struct_declaration322_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "semi", NULL);
    pt_node_accept (pt_struct_declaration322_semi (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_declaration382 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_declaration382", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_struct_declaration382_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_struct_declaration382_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_declaration_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_declaration_list", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_struct_declaration_list_prev (node) != NULL)
      pt_node_accept (pt_struct_declaration_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "attrs", NULL);
    pt_node_accept (pt_struct_declaration_list_attrs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decl", NULL);
    pt_node_accept (pt_struct_declaration_list_decl (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_declarator (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_declarator", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decl", NULL);
    pt_node_accept (pt_struct_declarator_decl (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "bitfield", NULL);
    pt_node_accept (pt_struct_declarator_bitfield (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "attrs", NULL);
    pt_node_accept (pt_struct_declarator_attrs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_declaring_list325 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_declaring_list325", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_struct_declaring_list325_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_struct_declaring_list325_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_declaring_list326 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_declaring_list326", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_struct_declaring_list326_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_struct_declaring_list326_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_struct_declaring_list326_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_declaring_list327 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_declaring_list327", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_struct_declaring_list327_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    pt_node_accept (pt_struct_declaring_list327_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_struct_declaring_list327_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_declaring_list392 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_declaring_list392", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_struct_declaring_list392_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_struct_declaring_list392_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_struct_declaring_list392_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_struct_declaring_list392_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_default_declaring_list323 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_default_declaring_list323", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_struct_default_declaring_list323_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_struct_default_declaring_list323_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_default_declaring_list324 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_default_declaring_list324", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_struct_default_declaring_list324_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    pt_node_accept (pt_struct_default_declaring_list324_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_struct_default_declaring_list324_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_identifier_declarator (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_identifier_declarator", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decl", NULL);
    pt_node_accept (pt_struct_identifier_declarator_decl (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "bitfield", NULL);
    pt_node_accept (pt_struct_identifier_declarator_bitfield (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "attrs", NULL);
    pt_node_accept (pt_struct_identifier_declarator_attrs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_struct_or_union_specifier (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "struct_or_union_specifier", NULL);
  xmlNewProp (self->cur, "members", itoa (5));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "sudcl", NULL);
    pt_node_accept (pt_struct_or_union_specifier_sudcl (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "id", NULL);
    if (pt_struct_or_union_specifier_id (node) != NULL)
      pt_node_accept (pt_struct_or_union_specifier_id (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrace", NULL);
    if (pt_struct_or_union_specifier_lbrace (node) != NULL)
      pt_node_accept (pt_struct_or_union_specifier_lbrace (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "fields", NULL);
    if (pt_struct_or_union_specifier_fields (node) != NULL)
      pt_node_accept (pt_struct_or_union_specifier_fields (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrace", NULL);
    if (pt_struct_or_union_specifier_rbrace (node) != NULL)
      pt_node_accept (pt_struct_or_union_specifier_rbrace (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_subtract (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "subtract", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_subtract_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_subtract_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_subtract_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_subtract_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "subtract_assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_subtract_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_subtract_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_subtract_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_sue_declaration_specifier25 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "sue_declaration_specifier25", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_sue_declaration_specifier25_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_sue_declaration_specifier25_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_sue_declaration_specifier26 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "sue_declaration_specifier26", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_sue_declaration_specifier26_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_sue_declaration_specifier26_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    pt_node_accept (pt_sue_declaration_specifier26_n3 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_sue_declaration_specifier27 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "sue_declaration_specifier27", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_sue_declaration_specifier27_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_sue_declaration_specifier27_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_sue_type_specifier44 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "sue_type_specifier44", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    if (pt_sue_type_specifier44_n1 (node) != NULL)
      pt_node_accept (pt_sue_type_specifier44_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_sue_type_specifier44_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_sue_type_specifier46 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "sue_type_specifier46", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_sue_type_specifier46_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_sue_type_specifier46_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_switch_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "switch_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (5));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "switch_tok", NULL);
    pt_node_accept (pt_switch_statement_switch_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_switch_statement_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_switch_statement_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_switch_statement_rbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "stmt", NULL);
    pt_node_accept (pt_switch_statement_stmt (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_ternary_op (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "ternary_op", NULL);
  xmlNewProp (self->cur, "members", itoa (5));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "cond", NULL);
    pt_node_accept (pt_ternary_op_cond (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "qmark", NULL);
    pt_node_accept (pt_ternary_op_qmark (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "then_expr", NULL);
    if (pt_ternary_op_then_expr (node) != NULL)
      pt_node_accept (pt_ternary_op_then_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "colon", NULL);
    pt_node_accept (pt_ternary_op_colon (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "else_expr", NULL);
    pt_node_accept (pt_ternary_op_else_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_translation_unit (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "translation_unit", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_translation_unit_prev (node) != NULL)
      pt_node_accept (pt_translation_unit_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "def", NULL);
    pt_node_accept (pt_translation_unit_def (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_type_cast (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "type_cast", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_type_cast_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "type", NULL);
    pt_node_accept (pt_type_cast_type (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_type_cast_rbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_type_cast_expr (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_type_name (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "type_name", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "tspec", NULL);
    pt_node_accept (pt_type_name_tspec (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decl", NULL);
    if (pt_type_name_decl (node) != NULL)
      pt_node_accept (pt_type_name_decl (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_type_name151 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "type_name151", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "tquals", NULL);
    pt_node_accept (pt_type_name151_tquals (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "defint", NULL);
    pt_node_accept (pt_type_name151_defint (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "decl", NULL);
    if (pt_type_name151_decl (node) != NULL)
      pt_node_accept (pt_type_name151_decl (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_type_qualifier_list (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "type_qualifier_list", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "prev", NULL);
    if (pt_type_qualifier_list_prev (node) != NULL)
      pt_node_accept (pt_type_qualifier_list_prev (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "qual", NULL);
    pt_node_accept (pt_type_qualifier_list_qual (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_type_qualifier_opt270 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "type_qualifier_opt270", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_type_qualifier_opt270_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_type_qualifier_opt271 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "type_qualifier_opt271", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_type_qualifier_opt271_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_type_specifier_nosue387 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "type_specifier_nosue387", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_type_specifier_nosue387_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_typedef_declaration_specifier28 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "typedef_declaration_specifier28", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_typedef_declaration_specifier28_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_typedef_declaration_specifier28_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_typedef_declaration_specifier29 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "typedef_declaration_specifier29", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_typedef_declaration_specifier29_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_typedef_declaration_specifier29_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_typedef_declaration_specifier30 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "typedef_declaration_specifier30", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_typedef_declaration_specifier30_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_typedef_declaration_specifier30_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_typedef_str_class_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "typedef_str_class_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "typedef_tok", NULL);
    pt_node_accept (pt_typedef_str_class_spec_typedef_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_typedef_type_specifier47 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "typedef_type_specifier47", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    if (pt_typedef_type_specifier47_n1 (node) != NULL)
      pt_node_accept (pt_typedef_type_specifier47_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_typedef_type_specifier47_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_typedef_type_specifier49 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "typedef_type_specifier49", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_typedef_type_specifier49_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_typedef_type_specifier49_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_typeof_expression388 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "typeof_expression388", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_typeof_expression388_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_typeof_expression389 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "typeof_expression389", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_typeof_expression389_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_typeof_type_specifier (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "typeof_type_specifier", NULL);
  xmlNewProp (self->cur, "members", itoa (5));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "tquals", NULL);
    if (pt_typeof_type_specifier_tquals (node) != NULL)
      pt_node_accept (pt_typeof_type_specifier_tquals (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "typeof_tok", NULL);
    pt_node_accept (pt_typeof_type_specifier_typeof_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_typeof_type_specifier_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_typeof_type_specifier_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_typeof_type_specifier_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_unary_expression383 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "unary_expression383", NULL);
  xmlNewProp (self->cur, "members", itoa (2));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_unary_expression383_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_unary_expression383_n2 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_unary_identifier_declarator94 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "unary_identifier_declarator94", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_unary_identifier_declarator94_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_unary_identifier_declarator95 (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "unary_identifier_declarator95", NULL);
  xmlNewProp (self->cur, "members", itoa (4));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_unary_identifier_declarator95_n1 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n2", NULL);
    pt_node_accept (pt_unary_identifier_declarator95_n2 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n3", NULL);
    if (pt_unary_identifier_declarator95_n3 (node) != NULL)
      pt_node_accept (pt_unary_identifier_declarator95_n3 (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n4", NULL);
    pt_node_accept (pt_unary_identifier_declarator95_n4 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_union (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "union", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "union_tok", NULL);
    pt_node_accept (pt_union_union_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_unsigned_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "unsigned_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "unsigned_tok", NULL);
    pt_node_accept (pt_unsigned_type_spec_unsigned_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_va_arg_expression (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "va_arg_expression", NULL);
  xmlNewProp (self->cur, "members", itoa (6));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "va_arg_op", NULL);
    pt_node_accept (pt_va_arg_expression_va_arg_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_va_arg_expression_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "expr", NULL);
    pt_node_accept (pt_va_arg_expression_expr (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "comma", NULL);
    pt_node_accept (pt_va_arg_expression_comma (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "type", NULL);
    pt_node_accept (pt_va_arg_expression_type (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_va_arg_expression_rbrack (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_va_list_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "va_list_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "n1", NULL);
    pt_node_accept (pt_va_list_type_spec_n1 (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_void_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "void_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "void_tok", NULL);
    pt_node_accept (pt_void_type_spec_void_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_volatile_type_qualifier (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "volatile_type_qualifier", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "volatile_tok", NULL);
    pt_node_accept (pt_volatile_type_qualifier_volatile_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_wchar_constant (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "wchar_constant", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "token", NULL);
    pt_node_accept (pt_wchar_constant_token (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_wchar_type_spec (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "wchar_type_spec", NULL);
  xmlNewProp (self->cur, "members", itoa (1));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "wchar_tok", NULL);
    pt_node_accept (pt_wchar_type_spec_wchar_tok (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_while_statement (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "while_statement", NULL);
  xmlNewProp (self->cur, "members", itoa (5));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "while_tok", NULL);
    pt_node_accept (pt_while_statement_while_tok (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lbrack", NULL);
    pt_node_accept (pt_while_statement_lbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "cond", NULL);
    pt_node_accept (pt_while_statement_cond (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rbrack", NULL);
    pt_node_accept (pt_while_statement_rbrack (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "stmt", NULL);
    pt_node_accept (pt_while_statement_stmt (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}

static void
pt_print_visitor_visit_xor_assign (struct visitor_type *object, struct node_type const *node)
{
  struct xmlNodePtr const last = self->cur;

  self->cur = xmlNewChild (self->cur, NULL, "xor_assign", NULL);
  xmlNewProp (self->cur, "members", itoa (3));

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "lhs", NULL);
    pt_node_accept (pt_xor_assign_lhs (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "op", NULL);
    pt_node_accept (pt_xor_assign_op (node), &self->base);
    self->cur = last;
  }

  {
    struct xmlNodePtr const last = self->cur;
    self->cur = xmlNewChild (self->cur, NULL, "rhs", NULL);
    pt_node_accept (pt_xor_assign_rhs (node), &self->base);
    self->cur = last;
  }

  self->cur = last;
}


static struct xmlChar const *
xml_loc (int line, int column)
{
  static char buf[64];

  snprintf (buf, sizeof buf, "%d:%d", line, column);
  return buf;
}

static struct xmlChar const *
xml_escape (char const *text)
{
  static struct xmlChar buf[1024];
  struct xmlChar *ptr = buf;
  char c;

  while ((c = *text++) != '\0')
    switch (c)
      {
      case '&':
        assert (ptr - buf < sizeof buf - 5);
        *ptr++ = '&';
        *ptr++ = 'a';
        *ptr++ = 'm';
        *ptr++ = 'p';
        *ptr++ = ';';
        break;
      default:
        assert (ptr - buf < sizeof buf);
        *ptr++ = c;
        break;
      }

  *ptr = '\0';
  buf[sizeof buf - 1] = '\0';

  return buf;
}

static void
pt_print_visitor_visit_token (struct visitor_type *object, struct node_type const *node)
{
  struct location const *loc = pt_node_location (node);

  struct xmlNodePtr xmltok = xmlNewChild (self->cur, NULL, "token", xml_escape (pt_token_text (node)));
  xmlNewProp (xmltok, "left",  xml_loc (loc->first_line, loc->first_column));
  xmlNewProp (xmltok, "right", xml_loc (loc->last_line , loc->last_column ));
  xmlNewProp (xmltok, "token", itoa (pt_token_token (node)));
}

static struct pt_visitor_vtbl pt_print_visitor_vtbl = {
  {
    "pt_visitor",
    sizeof (struct self_type),
  },
  pt_print_visitor_visit_token,
  pt_print_visitor_visit_add,
  pt_print_visitor_visit_add_assign,
  pt_print_visitor_visit_address_of,
  pt_print_visitor_visit_alignof_type,
  pt_print_visitor_visit_alignof_var,
  pt_print_visitor_visit_and_assign,
  pt_print_visitor_visit_any_word115,
  pt_print_visitor_visit_any_word116,
  pt_print_visitor_visit_any_word117,
  pt_print_visitor_visit_argument_expression_list,
  pt_print_visitor_visit_array_abstract_declarator,
  pt_print_visitor_visit_array_abstract_declarator_list,
  pt_print_visitor_visit_array_access,
  pt_print_visitor_visit_array_labelled_initialised,
  pt_print_visitor_visit_asm361,
  pt_print_visitor_visit_asm_argument,
  pt_print_visitor_visit_asm_argument_list,
  pt_print_visitor_visit_asm_argument_list_opt362,
  pt_print_visitor_visit_asm_clobbered_list,
  pt_print_visitor_visit_asm_opt359,
  pt_print_visitor_visit_asm_opt360,
  pt_print_visitor_visit_asm_statement,
  pt_print_visitor_visit_assign,
  pt_print_visitor_visit_attrib375,
  pt_print_visitor_visit_attrib376,
  pt_print_visitor_visit_attrib377,
  pt_print_visitor_visit_attrib378,
  pt_print_visitor_visit_attrib379,
  pt_print_visitor_visit_attribute,
  pt_print_visitor_visit_attribute_list373,
  pt_print_visitor_visit_attribute_list374,
  pt_print_visitor_visit_attributes370,
  pt_print_visitor_visit_attributes371,
  pt_print_visitor_visit_attributes_opt368,
  pt_print_visitor_visit_attributes_opt369,
  pt_print_visitor_visit_auto_str_class_spec,
  pt_print_visitor_visit_basic_declaration_specifier21,
  pt_print_visitor_visit_basic_declaration_specifier22,
  pt_print_visitor_visit_basic_declaration_specifier23,
  pt_print_visitor_visit_basic_declaration_specifier24,
  pt_print_visitor_visit_basic_type_specifier41,
  pt_print_visitor_visit_basic_type_specifier42,
  pt_print_visitor_visit_basic_type_specifier43,
  pt_print_visitor_visit_bit_field_size,
  pt_print_visitor_visit_bit_field_size_opt330,
  pt_print_visitor_visit_bit_field_size_opt331,
  pt_print_visitor_visit_bitwise_and,
  pt_print_visitor_visit_bitwise_negate,
  pt_print_visitor_visit_bitwise_or,
  pt_print_visitor_visit_bitwise_xor,
  pt_print_visitor_visit_brace_expression,
  pt_print_visitor_visit_bracket_expression,
  pt_print_visitor_visit_bracketed_initialiser_list,
  pt_print_visitor_visit_break_statement,
  pt_print_visitor_visit_case_label_statement,
  pt_print_visitor_visit_char_constant,
  pt_print_visitor_visit_char_type_spec,
  pt_print_visitor_visit_clean_postfix_typedef_declarator76,
  pt_print_visitor_visit_clean_postfix_typedef_declarator77,
  pt_print_visitor_visit_clean_typedef_declarator73,
  pt_print_visitor_visit_clean_typedef_declarator74,
  pt_print_visitor_visit_clean_typedef_declarator75,
  pt_print_visitor_visit_comma_expression,
  pt_print_visitor_visit_comma_opt340,
  pt_print_visitor_visit_comma_opt341,
  pt_print_visitor_visit_complex_type_qualifier,
  pt_print_visitor_visit_compound_literal,
  pt_print_visitor_visit_compound_statement,
  pt_print_visitor_visit_const_type_qualifier,
  pt_print_visitor_visit_continue_statement,
  pt_print_visitor_visit_declaration1,
  pt_print_visitor_visit_declaration2,
  pt_print_visitor_visit_declaration3,
  pt_print_visitor_visit_declaration4,
  pt_print_visitor_visit_declaration5,
  pt_print_visitor_visit_declaration6,
  pt_print_visitor_visit_declaration7,
  pt_print_visitor_visit_declaration8,
  pt_print_visitor_visit_declaration_list,
  pt_print_visitor_visit_declaration_qualifier_list31,
  pt_print_visitor_visit_declaration_qualifier_list32,
  pt_print_visitor_visit_declaration_qualifier_list33,
  pt_print_visitor_visit_declarator384,
  pt_print_visitor_visit_declaring_list10,
  pt_print_visitor_visit_declaring_list11,
  pt_print_visitor_visit_declaring_list12,
  pt_print_visitor_visit_declaring_list13,
  pt_print_visitor_visit_declaring_list9,
  pt_print_visitor_visit_default_declaring_list14,
  pt_print_visitor_visit_default_declaring_list15,
  pt_print_visitor_visit_default_declaring_list16,
  pt_print_visitor_visit_default_int,
  pt_print_visitor_visit_default_label_statement,
  pt_print_visitor_visit_designated_initialiser,
  pt_print_visitor_visit_divide,
  pt_print_visitor_visit_divide_assign,
  pt_print_visitor_visit_do_statement,
  pt_print_visitor_visit_double_type_spec,
  pt_print_visitor_visit_enum_specifier,
  pt_print_visitor_visit_enumerator_list,
  pt_print_visitor_visit_enumerator_value_opt338,
  pt_print_visitor_visit_enumerator_value_opt339,
  pt_print_visitor_visit_equals,
  pt_print_visitor_visit_expression_opt250,
  pt_print_visitor_visit_expression_opt254,
  pt_print_visitor_visit_expression_statement,
  pt_print_visitor_visit_extern_str_class_spec,
  pt_print_visitor_visit_external_definition385,
  pt_print_visitor_visit_float_type_spec,
  pt_print_visitor_visit_floating_constant,
  pt_print_visitor_visit_for_statement,
  pt_print_visitor_visit_fullold_function_declarator,
  pt_print_visitor_visit_function_call,
  pt_print_visitor_visit_function_definition,
  pt_print_visitor_visit_function_definition_dqual,
  pt_print_visitor_visit_function_definition_tqual,
  pt_print_visitor_visit_gcc_extension386,
  pt_print_visitor_visit_goto_statement,
  pt_print_visitor_visit_greater_than,
  pt_print_visitor_visit_greater_than_equals,
  pt_print_visitor_visit_hex_constant,
  pt_print_visitor_visit_identifier_list,
  pt_print_visitor_visit_if_statement,
  pt_print_visitor_visit_imag_expression,
  pt_print_visitor_visit_initialiser121,
  pt_print_visitor_visit_initialiser_list,
  pt_print_visitor_visit_initialiser_opt118,
  pt_print_visitor_visit_initialiser_opt119,
  pt_print_visitor_visit_inline_type_qualifier,
  pt_print_visitor_visit_int_type_spec,
  pt_print_visitor_visit_integer_constant,
  pt_print_visitor_visit_label_statement,
  pt_print_visitor_visit_left_shift_assign,
  pt_print_visitor_visit_less_than,
  pt_print_visitor_visit_less_than_equals,
  pt_print_visitor_visit_logical_and,
  pt_print_visitor_visit_logical_not,
  pt_print_visitor_visit_logical_or,
  pt_print_visitor_visit_long_type_spec,
  pt_print_visitor_visit_modulo,
  pt_print_visitor_visit_modulo_assign,
  pt_print_visitor_visit_multiply,
  pt_print_visitor_visit_multiply_assign,
  pt_print_visitor_visit_negate,
  pt_print_visitor_visit_not_equals,
  pt_print_visitor_visit_octal_constant,
  pt_print_visitor_visit_old_function_declarator102,
  pt_print_visitor_visit_old_function_declarator103,
  pt_print_visitor_visit_old_function_definition_dspec,
  pt_print_visitor_visit_old_function_definition_tspec,
  pt_print_visitor_visit_or_assign,
  pt_print_visitor_visit_parameter_declaration139,
  pt_print_visitor_visit_parameter_declaration140,
  pt_print_visitor_visit_parameter_declaration141,
  pt_print_visitor_visit_parameter_declaration142,
  pt_print_visitor_visit_parameter_declaration143,
  pt_print_visitor_visit_parameter_declaration144,
  pt_print_visitor_visit_parameter_declaration145,
  pt_print_visitor_visit_parameter_declaration146,
  pt_print_visitor_visit_parameter_declaration156,
  pt_print_visitor_visit_parameter_declaration157,
  pt_print_visitor_visit_parameter_declaration158,
  pt_print_visitor_visit_parameter_list,
  pt_print_visitor_visit_parameter_type_list135,
  pt_print_visitor_visit_parameter_typedef_declarator70,
  pt_print_visitor_visit_parameter_typedef_declarator71,
  pt_print_visitor_visit_parameter_typedef_declarator72,
  pt_print_visitor_visit_paren_identifier_declarator100,
  pt_print_visitor_visit_paren_identifier_declarator101,
  pt_print_visitor_visit_paren_postfix_typedef_declarator65,
  pt_print_visitor_visit_paren_postfix_typedef_declarator66,
  pt_print_visitor_visit_paren_postfix_typedef_declarator67,
  pt_print_visitor_visit_paren_typedef_declarator60,
  pt_print_visitor_visit_paren_typedef_declarator61,
  pt_print_visitor_visit_paren_typedef_declarator62,
  pt_print_visitor_visit_paren_typedef_declarator63,
  pt_print_visitor_visit_paren_typedef_declarator64,
  pt_print_visitor_visit_pointer,
  pt_print_visitor_visit_pointer_access,
  pt_print_visitor_visit_pointer_dereference,
  pt_print_visitor_visit_pointer_type_qualifier_list,
  pt_print_visitor_visit_positive,
  pt_print_visitor_visit_post_decrement,
  pt_print_visitor_visit_post_increment,
  pt_print_visitor_visit_postfix_abstract_declarator85,
  pt_print_visitor_visit_postfix_abstract_declarator86,
  pt_print_visitor_visit_postfix_abstract_declarator87,
  pt_print_visitor_visit_postfix_abstract_declarator88,
  pt_print_visitor_visit_postfix_identifier_declarator97,
  pt_print_visitor_visit_postfix_identifier_declarator98,
  pt_print_visitor_visit_postfix_identifier_declarator99,
  pt_print_visitor_visit_postfix_old_function_declarator105,
  pt_print_visitor_visit_postfix_old_function_declarator106,
  pt_print_visitor_visit_postfixing_abstract_declarator89,
  pt_print_visitor_visit_postfixing_abstract_declarator90,
  pt_print_visitor_visit_pre_decrement,
  pt_print_visitor_visit_pre_increment,
  pt_print_visitor_visit_qualifier_list159,
  pt_print_visitor_visit_qualifier_list160,
  pt_print_visitor_visit_real_expression,
  pt_print_visitor_visit_register_str_class_spec,
  pt_print_visitor_visit_restrict_pointer_type_qualifier,
  pt_print_visitor_visit_restrict_type_qualifier,
  pt_print_visitor_visit_return_statement,
  pt_print_visitor_visit_right_shift_assign,
  pt_print_visitor_visit_shift_left,
  pt_print_visitor_visit_shift_right,
  pt_print_visitor_visit_short_type_spec,
  pt_print_visitor_visit_signer_type_spec,
  pt_print_visitor_visit_simple_paren_typedef_declarator68,
  pt_print_visitor_visit_simple_paren_typedef_declarator69,
  pt_print_visitor_visit_sizeof_type,
  pt_print_visitor_visit_sizeof_var,
  pt_print_visitor_visit_statement350,
  pt_print_visitor_visit_statement_list,
  pt_print_visitor_visit_static_str_class_spec,
  pt_print_visitor_visit_string_literal_list,
  pt_print_visitor_visit_struct,
  pt_print_visitor_visit_struct_access,
  pt_print_visitor_visit_struct_declaration321,
  pt_print_visitor_visit_struct_declaration322,
  pt_print_visitor_visit_struct_declaration382,
  pt_print_visitor_visit_struct_declaration_list,
  pt_print_visitor_visit_struct_declarator,
  pt_print_visitor_visit_struct_declaring_list325,
  pt_print_visitor_visit_struct_declaring_list326,
  pt_print_visitor_visit_struct_declaring_list327,
  pt_print_visitor_visit_struct_declaring_list392,
  pt_print_visitor_visit_struct_default_declaring_list323,
  pt_print_visitor_visit_struct_default_declaring_list324,
  pt_print_visitor_visit_struct_identifier_declarator,
  pt_print_visitor_visit_struct_or_union_specifier,
  pt_print_visitor_visit_subtract,
  pt_print_visitor_visit_subtract_assign,
  pt_print_visitor_visit_sue_declaration_specifier25,
  pt_print_visitor_visit_sue_declaration_specifier26,
  pt_print_visitor_visit_sue_declaration_specifier27,
  pt_print_visitor_visit_sue_type_specifier44,
  pt_print_visitor_visit_sue_type_specifier46,
  pt_print_visitor_visit_switch_statement,
  pt_print_visitor_visit_ternary_op,
  pt_print_visitor_visit_translation_unit,
  pt_print_visitor_visit_type_cast,
  pt_print_visitor_visit_type_name,
  pt_print_visitor_visit_type_name151,
  pt_print_visitor_visit_type_qualifier_list,
  pt_print_visitor_visit_type_qualifier_opt270,
  pt_print_visitor_visit_type_qualifier_opt271,
  pt_print_visitor_visit_type_specifier_nosue387,
  pt_print_visitor_visit_typedef_declaration_specifier28,
  pt_print_visitor_visit_typedef_declaration_specifier29,
  pt_print_visitor_visit_typedef_declaration_specifier30,
  pt_print_visitor_visit_typedef_str_class_spec,
  pt_print_visitor_visit_typedef_type_specifier47,
  pt_print_visitor_visit_typedef_type_specifier49,
  pt_print_visitor_visit_typeof_expression388,
  pt_print_visitor_visit_typeof_expression389,
  pt_print_visitor_visit_typeof_type_specifier,
  pt_print_visitor_visit_unary_expression383,
  pt_print_visitor_visit_unary_identifier_declarator94,
  pt_print_visitor_visit_unary_identifier_declarator95,
  pt_print_visitor_visit_union,
  pt_print_visitor_visit_unsigned_type_spec,
  pt_print_visitor_visit_va_arg_expression,
  pt_print_visitor_visit_va_list_type_spec,
  pt_print_visitor_visit_void_type_spec,
  pt_print_visitor_visit_volatile_type_qualifier,
  pt_print_visitor_visit_wchar_constant,
  pt_print_visitor_visit_wchar_type_spec,
  pt_print_visitor_visit_while_statement,
  pt_print_visitor_visit_xor_assign,
};

static void
pt_print_visitor_construct (struct self_type *self, struct FILE *fh)
{
  assert (self != NULL);
  assert (fh != NULL);

  pt_visitor_construct (&self->base, &pt_print_visitor_vtbl);

  self->doc = xmlNewDoc ("1.0");
  self->cur = xmlNewNode (NULL, "pt");
  self->fh = fh;

  xmlDocSetRootElement (self->doc, self->cur);
}

struct visitor_type *
pt_print_visitor_new (struct FILE *fh)
{
  return NEW (print_visitor, fh);
}

void
pt_print_visitor_delete (struct visitor_type *object)
{
  xmlDocDump (self->fh, self->doc);
  xmlFreeDoc (self->doc);

  mem_free (self, self->base.vtbl->ti.size);
}
