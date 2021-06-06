import json
import matplotlib.pyplot as plt
import numpy as np

with open('c:/Users/alvar/Documents/GitHub/District-Dance-Battle/Python/info.json') as f:
    data = json.load(f)

input_events = []
log_events = []
lostlevel_events = []
dialogskip_events = []

for i in range(len(data["events"])):
    if data["events"][i]['event_type'] == "INPUT_EVENT":
        input_events.append(data["events"][i])


distances = [0,0,0,0,0,0]

for i in range(len(input_events)):
    distance = input_events[i]['distance']
    if distance > 0.0 and distance <= 2.0:
        distances[0]+=1
    if distance > 2.0 and distance <= 4.0:
        distances[1]+=1
    if distance > 4.0 and distance <= 6.0:
        distances[2]+=1
    if distance > 6.0 and distance <= 8.0:
        distances[3]+=1
    if distance > 8.0 and distance <= 10.0:
        distances[4]+=1
    if distance > 10.0 and distance <= 12.0:
        distances[5]+=1

fig = plt.figure()
#ax = fig.add_axes([0,0,1,1])
langs = ['0-2', '2-4', '4-6', '6-8', '8-10', '10-12']
#y_pos = np.arange(len(langs))
#plt.xticks(y_pos, langs)
plt.ylabel('Inputs')
plt.bar(langs,distances)
plt.suptitle('Grafico de distancias total')
plt.show()
