import json
import matplotlib.pyplot as plt
import numpy as np

with open('c:/Users/alvar/Documents/GitHub/District-Dance-Battle/Python/infoTest.json') as f:
    data = json.load(f)

level_events = []

for i in range(len(data["events"])):
    if data["events"][i]['event_type'] == "LEVEL_EVENT":
        level_events.append(data["events"][i])

sumas = [0,0,0,0,0]
divs = [0,0,0,0,0]

for i in range(len(level_events)):
    maxCombo = level_events[i]['max_combo_count']
    
    if level_events[i]['level'] == 1:
        sumas[0] += maxCombo
        divs[0] +=1
    if level_events[i]['level'] == 2:
        sumas[1] += maxCombo
        divs[1] +=1
    if level_events[i]['level'] == 3:
        sumas[2] += maxCombo
        divs[2] +=1
    if level_events[i]['level'] == 4:
        sumas[3] += maxCombo
        divs[3] +=1
    if level_events[i]['level'] == 5:
        sumas[4] += maxCombo
        divs[4] +=1

medias = [0,0,0,0,0]

for i in range(len(medias)):
    if divs[i] != 0:
        medias[i] = sumas[i]/divs[i]

fig = plt.figure()
#ax = fig.add_axes([0,0,1,1])
lvls = [1,2,3,4,5]
#y_pos = np.arange(len(lvls))
#plt.xticks(y_pos, lvls)
plt.xlabel('Nivel')
plt.ylabel('Max Combo')
plt.bar(lvls, medias)
plt.suptitle('Medias de combo máximo por nivel')
plt.show()