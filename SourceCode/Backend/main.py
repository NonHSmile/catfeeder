from flask import Flask , render_template,url_for , request
app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html')


@app.route('/music', methods=['GET'])
def find():
    
    music = request.args.get('music')
    cs = open('conmu.txt','w')
    cs.write(music)
    cs.close()
    return render_template('index.html')


@app.route('/feed', methods=['GET'])
def feed():
    cs = open('conser.txt','w')
    cs.write('1')
    cs.close()
    return render_template('index.html')


if __name__ == '__main__':
    app.run(host="0.0.0.0", port=5000, debug=True)

