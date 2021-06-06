import json
import matplotlib.pyplot as plt
import numpy as np

with open('c:/Users/alvar/Documents/GitHub/District-Dance-Battle/Python/info.json') as f:
    data = json.load(f)

lost_level_events = []
eventAux = 0

for i in range(len(data["events"])):
    if data["events"][i]['event_type'] == "LOST_LEVEL_EVENT":
        if data["events"][i]['score'] != eventAux:
            lost_level_events.append(data["events"][i])
            eventAux = data["events"][i]['score']

sumas = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

for i in range(len(lost_level_events)):
    if lost_level_events[i]['level'] == 2:
        sumas[0] += 1
    if lost_level_events[i]['level'] == 14:
        sumas[1] += 1
    if lost_level_events[i]['level'] == 5:
        sumas[2] += 1
    if lost_level_events[i]['level'] == 19:
        sumas[3] += 1
    if lost_level_events[i]['level'] == 22:
        sumas[4] += 1
    if lost_level_events[i]['level'] == 21:
        sumas[5] += 1
    if lost_level_events[i]['level'] == 12:
        sumas[6] += 1
    if lost_level_events[i]['level'] == 28:
        sumas[7] += 1
    if lost_level_events[i]['level'] == 24:
        sumas[8] += 1
    if lost_level_events[i]['level'] == 11:
        sumas[9] += 1
    if lost_level_events[i]['level'] == 34:
        sumas[10] += 1
    if lost_level_events[i]['level'] == 27:
        sumas[11] += 1
    if lost_level_events[i]['level'] == 30:
        sumas[12] += 1
    if lost_level_events[i]['level'] == 15:
        sumas[13] += 1
    if lost_level_events[i]['level'] == 26:
        sumas[14] += 1
    if lost_level_events[i]['level'] == 29:
        sumas[15] += 1
    if lost_level_events[i]['level'] == 10:
        sumas[16] += 1
    if lost_level_events[i]['level'] == 25:
        sumas[17] += 1
    if lost_level_events[i]['level'] == 9:
        sumas[18] += 1
    if lost_level_events[i]['level'] == 23:
        sumas[19] += 1


fig = plt.figure()
#ax = fig.add_axes([0,0,1,1])
#lvls = [1,2,3,4,5]
lvls = ["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"]
#y_pos = np.arange(len(lvls))
#plt.xticks(y_pos, lvls)
plt.xlabel('Nivel')
plt.ylabel('Veces perdido')
plt.bar(lvls, sumas)
plt.suptitle('Número de veces que se pierde cada nivel')
plt.show()