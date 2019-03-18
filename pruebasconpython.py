k = 0
i = 0
n = 0
m = 0
stringA = "aedabacdabab"
stringB = "ab"
A = ["a","e","d","a","b","a","c","d","a","b","a","b"]
B = ["a","b"]
indices = []
elementos = 0
n =len(A)
m = len(B)
while i < n:
    j = 0
    while A[i] == B[j]:
        i+=1
        elementos+=1
        if elementos == m:
            j = 0
            indices.append(i-m)
            elementos = 0
        else:
            if j < m:
                j += 1
            else:
                j = 0
    i+=1
print(indices)
