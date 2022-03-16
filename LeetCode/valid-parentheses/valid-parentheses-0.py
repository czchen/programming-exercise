class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for x in s:
            if x == '(' or x == '{' or x == '[':
                stack.append(x)

            else:
                if len(stack) == 0:
                    return False

                if x == ')' and stack[-1] == '(':
                    stack = stack[:-1]

                elif x == '}' and stack[-1] == '{':
                    stack = stack[:-1]

                elif x == ']' and stack[-1] == '[':
                    stack = stack[:-1]

                else:
                    return False

        return len(stack) == 0
