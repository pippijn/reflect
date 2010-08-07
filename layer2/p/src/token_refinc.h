struct token_refinc
{
  visitor_type base;

  stack *tokens;
};

void token_refinc_construct (struct token_refinc *self, stack *tokens);
void token_refinc_destruct (struct token_refinc *self);
