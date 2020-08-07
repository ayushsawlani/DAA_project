import random

def test(n,m):
    file1 = open("MyFile.txt","w")
    file1.write(str(n)+" "+str(m)+"\n")
    a = -1*(10**7)
    b = 2*(10**7)
    l = random.sample(range(a,b),n)
    #l = [71,69,65,74,68,75,67]
    for i in l:
        file1.write(str(i))
        file1.write(" ")
    return 0

if __name__=='__main__':
    n = 2000000
    m = 2000000
    test(n,m)
