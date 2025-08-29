from flask import Flask

app = Flask(__name__)

@app.route('/')
def index():
    return "<html><body><h1>I am hacker</h1></body></html>"

if __name__ == '__main__':
    app.run(host='10.106.40.53', port=80)

