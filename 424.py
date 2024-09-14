class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        from collections import defaultdict
        l_idx = 0
        freq = defaultdict(int)
        n = len(s)
        max_freq = 0
        max_length  = 0
        for i in range(n):
            freq[s[i]] += 1
            max_freq = max(max_freq, freq[s[i]])

            if not (i + 1 - l_idx - max_freq <= k):
                freq[s[l_idx]] -= 1
                l_idx += 1
            
            max_length = i + 1 - l_idx
        
        return max_length
