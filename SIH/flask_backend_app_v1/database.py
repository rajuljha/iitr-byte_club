###############     DATABASE CONNECTION      #######################
from sqlalchemy import create_engine, text
import os
from dotenv import load_dotenv
load_dotenv()

db_connection_string = os.environ['DB_CONNECTION_STRING']

engine = create_engine(db_connection_string)


# Create cursor and use it to execute SQL command
def get_jobs_from_db():
    with engine.connect() as conn:
        result = conn.execute(text("SELECT * FROM jobs"))
        jobs = []
        for row in result.mappings():
            jobs.append(dict(row))
        return jobs

def get_job_from_db(id):
    with engine.connect() as conn:
        result = conn.execute(text(f"SELECT * FROM jobs where id = :val"),dict(val=id))
        rows = []
        for row in result.mappings():
            rows.append(dict(row))
        return rows[0]

# ################## MYSQl Connector ##########################


import mysql.connector

def convert_to_binary(filename):
    with open(filename,'rb') as file:
        binaryData = file.read()
        return binaryData

def insertBLOB(emp_id, name, photo, biodataFile):
    print("Inserting BLOB into python_employee table")
    try:
        connection = mysql.connector.connect(host= os.environ.get('DB_HOST'),
                                            database= os.environ.get('DB_NAME'),
                                            user= os.environ.get('DB_USERNAME'),
                                            password= os.environ.get('DB_PASSWORD'))

        cursor = connection.cursor()
        sql_insert_blob_query = " INSERT INTO photos (id, name, photo, biodata) VALUES (%s,%s,%s,%s)"

        empPicture = convert_to_binary(photo)
        file = convert_to_binary(biodataFile)

        # Convert data into tuple format
        insert_blob_tuple = (emp_id, name, empPicture, file)
        result = cursor.execute(sql_insert_blob_query, insert_blob_tuple)
        connection.commit()
        print("Image and file inserted successfully as a BLOB into photos table", result)

    except mysql.connector.Error as error:
        print("Failed inserting BLOB data into MySQL table {}".format(error))

    finally:
        if connection.is_connected():
            cursor.close()
            connection.close()
            print("MySQL connection is closed")

# get_jobs_from_db()
insertBLOB(1,"Rajul","/Users/rajuljha/Downloads/planetscale.jpg","/Users/rajuljha/Downloads/Abstract for SIH 2023.pdf")

