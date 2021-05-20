from flask import Flask, request, jsonify, make_response
import json
import os

app = Flask(__name__)
filename = "../logs/data.txt"
app.filehandler = None
app.trackingList = []
app.isWorking = False

@app.route('/tracker', methods=['GET', 'POST'])
def track():
    if request.method == 'POST':
        if request.content_type == 'application/json':
            if not request.json:
                response = make_response("Bad format: JSON expected")
                response.status_code = 400
                return response
            if not 'data' in request.json:
                response = make_response('Bad format: JSON does not contain "data" property')
                response.status_code = 400
                return response   
            app.trackingList.append(request.json['data'])
        if request.content_type == 'text/plain':
            strData = request.get_data().decode("utf-8")
            lines = strData.split("\r\n")
            app.trackingList.extend(lines)
    
    return jsonify({'tracking': app.trackingList})
    
def toFile(response):
    if response.status_code == 200 and request.method == 'POST':
        if app.isWorking and len(app.trackingList)>0:
            print(app.trackingList[2])
            app.filehandler.write(app.trackingList[-1]+os.linesep)
            app.filehandler.flush()
        else:
            print("Could not write file: "+ filename)
    return response

def setup():
    try:
        if os.path.exists(filename):
            app.filehandler = open(filename, 'r+')
            app.trackingList = app.filehandler.read().splitlines() 
            app.isWorking = True
        else:
            app.filehandler = open(filename, 'w')
            app.trackingList = []
            app.isWorking = True
    except IOError:
        print ("Could not read file: "+ filename)


app.before_first_request(setup)
app.after_request(toFile)

if __name__ == '__main__':
    app.run(debug=False,host='0.0.0.0', port=8080)
