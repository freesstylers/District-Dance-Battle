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
    levels[i] = [[] for i in range(1000)]
    for j in range(len(levels[i])):
        levels[i][j] = 0

for i in range(len(input_events)):
    if input_events[i]["levelButton"] != input_events[i]["playerButton"]:
        levels[int(input_events[i]["nLevel"])][int(input_events[i]["numNote"])] += 1



