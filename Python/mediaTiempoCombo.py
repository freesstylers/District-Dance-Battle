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
divs = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

for i in range(len(level_events)):
    comboTime = level_events[i]['combo_time']
    
    if level_events[i]['level'] == 1:
        sumas[0] += comboTime
        divs[0] +=1
    if level_events[i]['level'] == 2:
        sumas[1] += comboTime
        divs[1] +=1
    if level_events[i]['level'] == 3:
        sumas[2] += comboTime
        divs[2] +=1
    if level_events[i]['level'] == 4:
        sumas[3] += comboTime
        divs[3] +=1
    if level_events[i]['level'] == 5:
        sumas[4] += comboTime
        divs[4] +=1
    if level_events[i]['level'] == 21:
        sumas[5] += comboTime
        divs[5] +=1
    if level_events[i]['level'] == 10:
        sumas[6] += comboTime
        divs[6] +=1
    if level_events[i]['level'] == 17:
        sumas[7] += comboTime
        divs[7] +=1
    if level_events[i]['level'] == 13:
        sumas[8] += comboTime
        divs[8] +=1
    if level_events[i]['level'] == 11:
        sumas[9] += comboTime
        divs[9] +=1
    if level_events[i]['level'] == 22:
        sumas[10] += comboTime
        divs[10] +=1
    if level_events[i]['level'] == 16:
        sumas[11] += comboTime
        divs[11] +=1
    if level_events[i]['level'] == 19:
        sumas[12] += comboTime
        divs[12] +=1
    if level_events[i]['level'] == 8:
        sumas[13] += comboTime
        divs[13] +=1
    if level_events[i]['level'] == 15:
        sumas[14] += comboTime
        divs[14] +=1
    if level_events[i]['level'] == 18:
        sumas[15] += comboTime
        divs[15] +=1
    if level_events[i]['level'] == 7:
        sumas[16] += comboTime
        divs[16] +=1
    if level_events[i]['level'] == 14:
        sumas[17] += comboTime
        divs[17] +=1
    if level_events[i]['level'] == 6:
        sumas[18] += comboTime
        divs[18] +=1
    if level_events[i]['level'] == 12:
        sumas[19] += comboTime
        divs[19] +=1

medias = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

for i in range(len(medias)):
    if divs[i] != 0:
        medias[i] = sumas[i]/divs[i]

fig = plt.figure()
#ax = fig.add_axes([0,0,1,1])
lvls = ["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"]
#y_pos = np.arange(len(lvls))
#plt.xticks(y_pos, lvls)
plt.xlabel('Nivel')
plt.ylabel('Tiempo de combo')
plt.bar(lvls, medias)
plt.suptitle('Medias de tiempo de combo por nivel')
plt.show()