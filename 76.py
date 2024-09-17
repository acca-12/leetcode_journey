class Solution:
    def minWindow(self, s: str, t: str) -> str:
        from collections import defaultdict
        l_w = 0
        r_w = 0 
        checkstr_len = len(s)
        freq_map = {char: t.count(char) for char in set(t)}
        substr_len = len(freq_map)
        num_at_0 = 0
        ans = float(inf), None, None
        while(r_w < checkstr_len):
            check = s[r_w]
            if(check in freq_map):
                freq_map[check] -= 1
                if(freq_map[check] == 0):
                    num_at_0 += 1

            while(l_w <= r_w and num_at_0 == substr_len):
                check_2 = s[l_w]
                if r_w - l_w + 1 < ans[0]:
                    ans = (r_w - l_w + 1, l_w, r_w)
                
                if(check_2 in freq_map):
                    freq_map[check_2] += 1
                    if(freq_map[check_2] > 0):
                        num_at_0 -= 1
                l_w += 1

            r_w += 1

        return "" if ans[0] == float('inf') else s[ans[1]: ans[2] + 1]
