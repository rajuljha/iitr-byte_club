from flask import Flask, render_template
from database import get_jobs_from_db, get_job_from_db
app = Flask(__name__)

@app.route("/")
def home():
    return render_template('home.html')

@app.route("/search_disease",methods=['POST','GET'])
def search_disease():
    jobs = get_jobs_from_db()
    return render_template("search_disease.html",
                        jobs=jobs)

if __name__ == "__main__":
    app.run(host='0.0.0.0', debug=True, port=5001)
