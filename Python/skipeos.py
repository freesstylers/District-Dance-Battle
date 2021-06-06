import json
import matplotlib.pyplot as plt
import numpy as np

with open('info.json') as f:
    data = json.load(f)

level_events = []
skip_events = []

for i in range(len(data["events"])):
    if data["events"][i]['event_type'] == "LEVEL_EVENT":
        level_events.append(data["events"][i])
    if data["events"][i]['event_type'] == "DIALOG_SKIP_EVENT":
        skip_events.append(data["events"][i])
    

x = [len(level_events), len(skip_events)]
y = ["Not Skipped", "Skipped"]

plt.pie(x , labels = y, autopct = '%1.1f%%')

plt.suptitle('Número de veces que se skipea el diálogo')
plt.show()