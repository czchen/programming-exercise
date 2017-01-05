class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if s == '' and p == '':
            return True

        memorization = {(0, 0)}
        stack = [(0, 0)]
        result = {
            'found_solution': False,
        }

        def add_to_stack(item):
            if item == (len(s), len(p)):
                result['found_solution'] = True
            elif item[0] > len(s) or item[1] == len(p):
                pass
            elif item not in memorization:
                stack.append(item)
                memorization.add(item)

        while stack and not result['found_solution']:
            item = stack.pop()

            if p[item[1] + 1: item[1] + 2] == '*':
                if p[item[1]: item[1] + 1] == '.' or p[item[1]: item[1] + 1] == s[item[0]: item[0] + 1]:
                    add_to_stack((item[0] + 1, item[1]))
                    add_to_stack((item[0] + 1, item[1] + 2))
                    add_to_stack((item[0] + 1, item[1]))
                add_to_stack((item[0], item[1] + 2))

            elif p[item[1]: item[1] + 1] == '.' or s[item[0]: item[0] + 1] == p[item[1]: item[1] + 1]:
                add_to_stack((item[0] + 1, item[1] + 1))

        return result['found_solution']
