from flask import Flask,jsonify, make_response,request
from functions import databaseentry, databaseread

app = Flask(__name__)

@app.route('/', methods=['GET'])
def home():
    return "Welcome to my API >:)"

@app.route('/input', methods=['GET'])
def entrypoint():
    ir=request.args.get("ir")
    hr=request.args.get("hr")
    output=databaseentry(ir, hr)
    return make_response(jsonify(output), 200)

@app.route('/output', methods=['GET'])
def exitpoint():
    output=databaseread()
    return make_response(jsonify(output), 200)
