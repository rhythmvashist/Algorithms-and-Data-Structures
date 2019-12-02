# You have a tree T with n vertices. Consider an ordering P=(v1,…,vn) of vertices of T. We construct a sequence A(P)=(a1,…,an) using the following process:

# Set all a[i]=−1.
# Process vertices in order v1,…,vn. For the current vertex vi set ai=MEX(au1,…,auk), where u1,…,uk is the set of neighbours of vi.
# For instance, let n=3 and T be the tree with edges (1,2) and (2,3). Then, for the ordering P=(1,2,3) we obtain the sequence A(P)=(0,1,0), while for the ordering P=(2,3,1) we obtain A(P)=(1,0,1).

# Consider all n! orders P. How many different sequences A(P) can we obtain? Print the answer modulo 109+7.You have a tree T with n vertices. Consider an ordering P=(v1,…,vn) of vertices of T. We construct a sequence A(P)=(a1,…,an) using the following process:

# Set all a[i]=−1.
# Process vertices in order v1,…,vn. For the current vertex vi set ai=MEX(au1,…,auk), where u1,…,uk is the set of neighbours of vi.
# For instance, let n=3 and T be the tree with edges (1,2) and (2,3). Then, for the ordering P=(1,2,3) we obtain the sequence A(P)=(0,1,0), while for the ordering P=(2,3,1) we obtain A(P)=(1,0,1).

# Consider all n! orders P. How many different sequences A(P) can we obtain? Print the answer modulo 109+7.
