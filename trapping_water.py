def trap(height):
    left_max = []
    right_max = []
    res = 0
    for i in range(len(height)):
        if(left_max==[]): 
            left_max.append(height[i])
            continue
        left_max.append(max(left_max[i-1],height[i]))
    k =1
    for i in range(len(arr)-1,-1,-1):
        if(right_max==[]):
            right_max.append(height[i])
            continue
        right_max.append(max(right_max[k-1],height[i]))
        k+=1
    right_max = right_max[::-1]
    for i in range(len(height)):
        min_val = min(left_max[i],right_max[i])
        add = min_val-height[i]
        res+=add
    print(res)
arr = [0,1,0,2,1,0,1,3,2,1,2,1]
trap(arr)