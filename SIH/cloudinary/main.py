from flask import Flask, render_template
from retrieve import get_img_url_from_db
from upload import upload_img_to_db

app = Flask(__name__)

@app.route("/",methods=['POST','GET'])
def home():
    img_url = get_img_url_from_db()
    return render_template('home.html',img_url=img_url)

@app.route('/upload', methods=['POST'])
def handle_upload():
    upload_img_to_db()
    return 'Image uploaded successfully!'


if __name__ == "__main__":
    app.run(debug=True)