// sample(button_click_handler)
void handle_click()
{
    // ...
}
// end-sample

struct button_t
{
    typedef void (*handler_t) ();

    void connect (handler_t h)
    { handler = h; }

    handler_t handler;
};

int main()
{
// sample(button_click_handler)
button_t button;
button.connect(&handle_click);
// end-sample

    return 0;
}
