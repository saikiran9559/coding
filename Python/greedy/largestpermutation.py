N, K = map(int, raw_input().split())
l = map(int, raw_input().split())

if K >= N:
    l.sort(reverse=True)
else:
    c = 0
    while c < K:
        if c == N:
            break
        maxIdx = l.index(max(l[c:]))
        if maxIdx == c:
            c += 1
            K += 1
            continue
        
        l[c], l[maxIdx] = l[maxIdx], l[c]
        c += 1

for i in xrange(N):
    print l[i],