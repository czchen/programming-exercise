char findLeft(char x) {
    switch (x) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default:
            break;
    }
    return 0;
}

bool isValid(const char *s) {

    char *stack = (char *) malloc(strlen(s));
    int ptr = 0;
    
    for (; *s; ++s) {
        switch (*s) {
            case '(':
            case '[':
            case '{':
                stack[ptr] = *s;
                ++ptr;
                break;

            case ')':
            case ']':
            case '}':
                if (ptr == 0) {
                    return false;
                }
                --ptr;

                if (stack[ptr] != findLeft(*s)) {
                    return false;
                }
                break;

            default:
                break;
        }
    }
    
    free(stack);
    
    if (ptr != 0) return false;
    return true;
}
