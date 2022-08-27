from typing import List

class Solution:
    def generateParenthesis(self, n:int) -> List[str]:
        answer = [{}, {"()"}]
        if n == 1:
            return list(answer[n])

        for i in range(2, n + 1):
            prev_paren_list = list(answer[i - 1])
            new_paren_set = set()
            for paren in prev_paren_list:
                for j in range(0, len(paren) + 1):
                    new = paren[0:j] + '()' + paren[j:]
                    new_paren_set.add(new)
            answer.append(new_paren_set)

        return list(answer[n])


if __name__ == '__main__':
    solution = Solution()
    n_str = input()
    n = int(n_str.split('=')[1])
    answer = solution.generateParenthesis(n)
    print(answer)
