import json
import matplotlib.pyplot as plt
import numpy as np

with open('c:/District-Dance-Battle/Python/info.json') as f:
    data = json.load(f)

level_events = []

for i in range(len(data["events"])):
    if data["events"][i]['event_type'] == "LEVEL_EVENT":
        level_events.append(data["events"][i])

#0 xbox, 1 ps4, 2 flechas, 3 teclado
input_types = [0,0,0,0]

ids_usadas = []

for i in range(len(level_events)):
    if level_events[i]["id_session"] in ids_usadas:
        continue
    else:
        if level_events[i]["input_type"] == "XBOX_INPUT":
            input_types[0]+=1
        if level_events[i]["input_type"] == "PS4_INPUT":
            input_types[1]+=1
        if level_events[i]["input_type"] == "ARROWS_INPUT":
            input_types[2]+=1
        if level_events[i]["input_type"] == "KEYBOARD_INPUT":
            input_types[3]+=1
        ids_usadas.append(level_events[i]["id_session"])

fig = plt.figure()
lvls = ["XBOX","PS4","ARROWS","KEYBOARD"]
plt.xlabel('Tipo de input')
plt.ylabel('Veces utilizado')
plt.bar(lvls, input_types)
plt.suptitle('Tipos de inputs utilizados')
plt.show()



