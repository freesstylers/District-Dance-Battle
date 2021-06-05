import json
import matplotlib.pyplot as plt
import numpy as np

with open('c:/District-Dance-Battle/Python/info.json') as f:
    data = json.load(f)

input_events = []

for i in range(len(data["events"])):
    if data["events"][i]['event_type'] == "INPUT_EVENT":
        input_events.append(data["events"][i])

levels = [[] for i in range(16)]

for i in range(len(levels)):
    levels[i].append(0)

for i in range(len(input_events)):
    if len(levels[int(input_events[i]["nLevel"])]) <= int(input_events[i]["numNote"]):
        levels[int(input_events[i]["nLevel"])].append(0)
    if input_events[i]["levelButton"] != input_events[i]["playerButton"]:
        levels[int(input_events[i]["nLevel"])][int(input_events[i]["numNote"])] += 1


# poner aqui el numero del nivel para sacar la grafica
level = levels[14]

y_pos = np.arange(len(level))
plt.bar(y_pos, level)
plt.show()



