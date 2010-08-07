struct token_collector
{
  visitor_type base;

  stack *tokens;
};

void token_collector_construct (struct token_collector *self);
void token_collector_destruct (struct token_collector *self);
