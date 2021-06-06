import json
import matplotlib.pyplot as plt
import numpy as np

with open('c:/Users/alvar/Documents/GitHub/District-Dance-Battle/Python/info.json') as f:
    data = json.load(f)

level_events = []

for i in range(len(data["events"])):
    if data["events"][i]['event_type'] == "LEVEL_EVENT":
        level_events.append(data["events"][i])

sumas = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

for i in range(len(level_events)):
    if level_events[i]['level'] == 1:
        sumas[0] += 1
    if level_events[i]['level'] == 2:
        sumas[1] += 1
    if level_events[i]['level'] == 3:
        sumas[2] += 1
    if level_events[i]['level'] == 4:
        sumas[3] += 1
    if level_events[i]['level'] == 5:
        sumas[4] += 1
    if level_events[i]['level'] == 21:
        sumas[5] += 1
    if level_events[i]['level'] == 10:
        sumas[6] += 1
    if level_events[i]['level'] == 17:
        sumas[7] += 1
    if level_events[i]['level'] == 13:
        sumas[8] += 1
    if level_events[i]['level'] == 11:
        sumas[9] += 1
    if level_events[i]['level'] == 22:
        sumas[10] += 1
    if level_events[i]['level'] == 16:
        sumas[11] += 1
    if level_events[i]['level'] == 19:
        sumas[12] += 1
    if level_events[i]['level'] == 8:
        sumas[13] += 1
    if level_events[i]['level'] == 15:
        sumas[14] += 1
    if level_events[i]['level'] == 18:
        sumas[15] += 1
    if level_events[i]['level'] == 7:
        sumas[16] += 1
    if level_events[i]['level'] == 14:
        sumas[17] += 1
    if level_events[i]['level'] == 6:
        sumas[18] += 1
    if level_events[i]['level'] == 12:
        sumas[19] += 1


fig = plt.figure()
#ax = fig.add_axes([0,0,1,1])
#lvls = ["LoFi", "Reggaeton", "Rap", "Rock", "HardBass", "Despacito", "Never", "Vengadores", "DotA", "Asereje", "Pop/Stars", "Doom", "Rasputin", "Running",
#"Tripoloski", "Dracukeo", "Megalovania", "Doraemon", "All Star", "Honk"]
lvls = ["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"]
#y_pos = np.arange(len(lvls))
#plt.xticks(y_pos, lvls)
plt.xlabel('Nivel')
plt.ylabel('Veces jugado')
plt.bar(lvls, sumas)
plt.suptitle('Número de veces que se juega cada nivel')
plt.show()