import matplotlib.pyplot as plt

N = 1000000
It = 1
Qt = 0
Rt = 0
St = N - It - Rt - Qt
beta = 0.8/N
mu = 0.06/N
etha = 3
gamma = 0.05

sus = [] # 시간 별로 susceptible host를 저장할 배열
inf = [] # 시간 별로 infectious host를 저장할 배열
rem = [] # 시간 별로 removal host를 저장할 배열
susrem = [] # 시간 별로 sus to removal host를 저장할 배열

def rate(St, It, Rt, Qt):
    t = 0
    global beta
    while (t < 300):
        beta = beta * ((1-It/N)**etha)
        It = It + (beta * St * It) + (mu * St * (It + Rt)) - (gamma * It) - (mu * St * (It + Rt)) # Infectious의 변화량
        St = St - (beta * St * It) - (mu * St*(It+Rt)) # Susceptible의 변화량
        Rt = Rt + (gamma * It) # Removal의 변화량
        Qt = Qt + (mu * St * (It+Rt)) # Sus to Removal의 변화량

        sus.append(St) # time이 변할 때 마다 각 항목의 값을 배열에 append.
        inf.append(It)
        rem.append(Rt)
        susrem.append(Qt)

        t += 1

rate(St, It, Rt, Qt)

plt.title("Two-Factor Model")

inf_val, = plt.plot(inf, label='Infectious')
sus_val, = plt.plot(sus, label='Susceptible')
rem_val, = plt.plot(rem, label='Removal')
susrem_val, = plt.plot(susrem, label='Sus to Removal')
plt.legend(handles=[inf_val, sus_val, rem_val, susrem_val])

plt.xlabel('Time')
plt.ylabel('Host')
plt.grid()

plt.show()
