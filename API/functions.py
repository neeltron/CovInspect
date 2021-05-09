import sqlite3

def databaseentry(ir,hr):
    con = sqlite3.connect('static/data.db')
    params = dict()
    try:
        with con:
                    cur = con.cursor()
                    cur.execute('INSERT OR IGNORE INTO data (ir,hr) VALUES (?, ?)', (ir,hr))
                    con.commit()
        params['status'] = "success"       
    except:
        params['status'] = "fail"
    return params

def databaseread():
    con = sqlite3.connect('static/data.db')
    params = dict()
    try:
        with con:
                    cur = con.cursor()
                    cur.execute("Select * from data order by id desc limit 1")
                    rows = cur.fetchall()
                    for row in rows:
                        id = row[0]
                        ir = row[1]
                        hr = row[2]
        params['id'] = id
        params['ir'] = ir
        params['hr'] = hr
    except:
        params['status'] = "fail"
    return params
