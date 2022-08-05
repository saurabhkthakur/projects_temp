import numpy as np
from flask import Flask, request, jsonify
from preprocess import Get_Pred
import joblib
import json
#model loading
model = joblib.load('model.pkl')


app = Flask(__name__)


# get data and perform prediction
@app.route('/predict',methods=['POST'])
def predict():
    
    data = request.json
    # mapping of user_input to handle multiple and missing inputs.
    user_input_dict = {'starting_age':"", 'gender':"", 'education':"", 'annual_income_self':"", 'loan_availed':"", 'total_financial_assets':"", 'marital_status':"", 
                            'occupation_self':"", 'home_owned':"", 'household':"", 'vehicle':"", 'dependents':"", 'travel':"", 'city':"" }
    
    feature = []
    
    for ind,val in data.items():
        # to handle multiple inputs that is given four wheeler,  two wheeler.
        if ind =='customer_id':
            continue 
        if not isinstance(data[ind],int) and len(data[ind].split(','))>1:
            user_input_dict[ind.lower()] =  [i.strip() for i in data[ind].split(',')] 
        else:
            user_input_dict[ind.lower()] = [val]
    
    feature = user_input_dict.values()

    preprocess = Get_Pred()
    user_input, original_weights = preprocess.input_process(feature)
    temp = preprocess.insurance_pred_dict(user_input,model,original_weights)
    # print(temp)
    sorted_recos = dict(sorted(temp.items(), key=lambda x:x[1], reverse=True))
  
    # recomendation = {policy[0]:policy[1] for policy in sorted_recos }
    sorted_recos['customer_id'] = data['customer_id']

    return json.dumps(sorted_recos)



if __name__ == '__main__':
    # run flask app
	app.run(port=8000)


