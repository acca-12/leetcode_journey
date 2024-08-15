class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack  = []

        for a in asteroids:
            if(a >= 0):
                stack.append(a)
            else:
                collidable = True
                while collidable:
                    if(not stack or stack[-1] < 0):
                        stack.append(a)
                        collidable = False
                    else:
                        if abs(a) > stack[-1]:
                            stack.pop()
                        elif abs(a) == stack[-1]:
                            stack.pop()
                            collidable = False
                        else:
                            collidable = False
        return stack
