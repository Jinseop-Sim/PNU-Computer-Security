import matplotlib.pyplot as plt

N = 1000000
It = 1
St = N - It
beta = 0.8/N

sus = [] # 시간이 증가함에 따라 각 항목 별로 값을 저장할 배열
inf = []

def rate(St, It, N):
    t = 0
    while (t < 100):
        It = It + (beta * St * It) # Infectious 변화량
        St = St - (beta * St * It) # Susceptible 변화량

        sus.append(St) # 시간이 증가 함에 따른 각 항목의 값을 배열에 append
        inf.append(It)
        t += 1

rate(St, It, N)

plt.title("SI Model")

sus_val, = plt.plot(sus, label='S(t)')
inf_val, =plt.plot(inf, label='I(t)')
plt.legend(handles=[inf_val, sus_val])

plt.xlabel('Time')
plt.ylabel('Host')
plt.grid()

plt.show()
