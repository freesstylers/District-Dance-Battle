import json
import matplotlib.pyplot as plt
import numpy as np

with open('c:/Users/alvar/Documents/GitHub/District-Dance-Battle/Python/infoTest.json') as f:
    data = json.load(f)

lost_level_events = []
eventAux = [0]

for i in range(len(data["events"])):
    if data["events"][i]['event_type'] == "LOST_LEVEL_EVENT":
        if data["events"][i]['score'] != eventAux[0]:
            lost_level_events.append(data["events"][i])
            eventAux[0] = data["events"][i]['score']

sumas = [0,0,0,0,0]

for i in range(len(lost_level_events)):
    if lost_level_events[i]['level'] == 1:
        sumas[0] += 1
    if lost_level_events[i]['level'] == 2:
        sumas[1] += 1
    if lost_level_events[i]['level'] == 3:
        sumas[2] += 1
    if lost_level_events[i]['level'] == 4:
        sumas[3] += 1
    if lost_level_events[i]['level'] == 5:
        sumas[4] += 1


fig = plt.figure()
#ax = fig.add_axes([0,0,1,1])
lvls = [1,2,3,4,5]
#y_pos = np.arange(len(lvls))
#plt.xticks(y_pos, lvls)
plt.xlabel('Nivel')
plt.ylabel('Veces perdido')
plt.bar(lvls, sumas)
plt.suptitle('Número de veces que se pierde cada nivel')
plt.show()