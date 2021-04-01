import matplotlib.pyplot as plt

N = 1000000
It = 1
Rt = 0
St = N - It - Rt
beta = 0.8/N
gamma = 0.05

sus = [] # 시간이 증가함에 따라 각 항목 별로 값을 저장할 배열
inf = []
rem = []

def rate(St, It, Rt):
    t = 0
    while (t < 100):
        It = It + (beta * St * It) - (gamma * It) # Infectious 변화량
        St = St - (beta * St * It) # Susceptible 변화량
        Rt = Rt + (gamma * It) # Removal 변화량

        sus.append(St) # 시간이 증가 함에 따른 각 항목의 값을 배열에 append
        inf.append(It)
        rem.append(Rt)

        t += 1

rate(St, It, Rt)

plt.title("SIR Model")

inf_val, = plt.plot(inf, label='I(t)')
sus_val, = plt.plot(sus, label='S(t)')
rem_val, = plt.plot(rem, label='R(t)')
plt.legend(handles=[inf_val, sus_val, rem_val])

plt.xlabel('Time')
plt.ylabel('Host')
plt.grid()

plt.show()
