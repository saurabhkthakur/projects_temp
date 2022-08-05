import numpy as np
from operator import add

class Get_Pred:

  def __init__(self):

    self.result = np.array([0]*17)
    self.insurance = ['two_wheeler_TP', 'two_wheeler_Comprehensive', 'Motor_TP','Motor_Comprehensive', 'Personal Accident Insurance', 
                      'Individual','Family Health Insurance', 'Critical Illness','Senior Citizen Health Insurance', 'Top Up Health Insurance',
                      'Hospital Daily cash', 'Contents', 'Building', 'Package','Home loan Insurance', 'Cyber Insurance', 'Travel Insurance']
    self.weight = {'age':{'20-30':[65,55,65,55,75,90,65,50,10,25,55,55,55,55,75,55,65],
                  '31-35':[55, 75, 55, 75, 75, 90, 75, 50, 10, 25, 75, 75, 65, 75, 85, 90, 75],
                  '35-45':[55, 75, 55, 75, 75, 75, 90, 60, 10, 90, 90, 85, 75, 90, 90, 90, 75],
                  '45-55':[55, 75, 55, 75, 75, 75, 90, 90, 10, 90, 90, 90, 75, 90, 90, 90, 85],
                  '55-64':[55, 75, 55, 75, 75, 55, 90, 90, 10, 90, 90, 90, 75, 90, 65, 90, 90],
                  '65+senior citizen':[25, 85, 25, 85, 65, 55, 45, 90, 90, 55, 25, 90, 75, 90, 55, 90, 10]},
 
                  'gender':{'Male':[70, 80, 70, 75, 90, 50, 80, 80, 90, 90, 90, 75, 90, 90, 90, 90, 90],
                            'Female':[20, 20, 20, 75, 50, 50, 50, 90, 65, 65, 75, 65, 75, 75, 55, 75, 75]},
        
                  'Education_Qualifications':{'Metriculate':[70, 70, 20, 75, 90, 65, 65, 65, 55, 55, 50, 65, 75, 75, 85, 55, 65],
                                              'Bachelors':[55, 90, 70, 70, 75, 85, 85, 85, 85, 85, 85, 85, 75, 75, 90, 90, 90],
                                              'Masters':[65, 90, 80, 80, 60, 90, 90, 90, 90, 90, 90, 85, 75, 75, 90, 90, 90]},
        
                  'Income':{'0-250000':[90, 65, 75, 55, 90, 75, 65, 55, 55, 50, 50, 45, 30, 45, 25, 25, 25],
                            '250000-500000':[90, 65, 75, 65, 75, 90, 75, 65, 65, 65, 65, 45, 30, 45, 25, 25, 25],
                            '500000-1000000':[75, 75, 65, 75, 75, 75, 90, 90, 75, 75, 65, 55, 30, 65, 50, 25, 55],
                            '1000000+':[55, 90, 55, 90, 75, 75, 90, 90, 90, 90, 90, 90, 75, 75, 90, 90, 90]},
        
                  'loans':{'Vehicle':[55, 90, 45, 90, 55, 90, 90, 75, 75, 75, 75, 75, 75, 75, 65, 90, 75],
                            'Home':[55, 90, 45, 90, 75, 75, 90, 75, 65, 85, 75, 75, 90, 90, 90, 90, 90]},
                  
                  'financial_asset':{'0-1000000':[50, 90, 55, 90, 90, 90, 75, 90, 65, 90, 90, 50, 55, 65, 90, 55, 55],
                                      '1000000-2000000':[40, 90, 50, 90, 90, 75, 90, 90, 75, 90, 75, 75, 65, 75, 90, 55, 75],
                                      '2000000-5000000':[20, 90, 40, 90, 90, 75, 90, 90, 90, 75, 65, 85, 90, 90, 90, 90, 85],
                                      '5000000-10000000':[20, 90, 35, 90, 90, 75, 90, 75, 75, 75, 65, 90, 90, 90, 85, 90, 85],
                                      '10000000+':[20, 90, 20, 90, 90, 65, 90, 75, 75, 65, 65, 90, 90, 90, 75, 90, 90]},
                  
                  'Married':{'yes':[55, 75, 55, 90, 90, 55, 90, 85, 75, 75, 75, 85, 75, 75, 90, 90, 90],
                              'No':[75, 75, 75, 90, 75, 95, 55, 75, 75, 65, 55, 50, 75, 75, 75, 60, 65]},
                  
                  'Occupations':{'work for a company':[65, 90, 65, 90, 90, 90, 90, 90, 90, 90, 90, 75, 75, 90, 85, 50, 75],
                                'Business Owner':[75, 90, 75, 90, 75, 85, 90, 90, 75, 90, 65, 90, 75, 90, 85, 90, 85],
                                'Freelancer':[75, 85, 50, 85, 90, 90, 85, 85, 65, 65, 65, 55, 55, 55, 65, 90, 75],
                                'NotEmployed/Retired':[75, 65, 65, 75, 75, 75, 70, 90, 90, 65, 90, 75, 85, 85, 25, 25, 25]},
                  
                  'House':{'own a independent house':[20, 90, 55, 90, 75, 65, 90, 90, 75, 90, 75, 90, 90, 90, 90, 90, 75],
                            'own an apartment':[20, 90, 55, 90, 75, 65, 90, 85, 75, 90, 75, 90, 20, 55, 90, 80, 80],
                            'rent':[55, 65, 55, 85, 75, 90, 90, 85, 75, 85, 75, 85, 15, 15, 55, 85, 75]},
                  
                  'Households':{'own high value electronics':[20, 90, 20, 90, 75, 75, 90, 85, 75, 75, 75, 95, 75, 85, 75, 90, 75],
                                'own jewellery and high end watches':[20, 90, 20, 90, 75, 75, 90, 85, 75, 75, 75, 95, 75, 85, 75, 90, 75]},
                  
                  'Vehicles':{'four wheeler':[20, 90, 90, 90, 75, 65, 90, 90, 75, 90, 65, 90, 75, 85, 75, 75, 75],
                              'two wheeler':[90, 90, 75, 75, 75, 90, 85, 65, 55, 75, 65, 50, 35, 50, 55, 65, 55]},
                           
                  'Dependents':{'Children':[65, 90, 65, 90, 90, 65, 90, 90, 25, 90, 75, 75, 85, 85, 85, 65, 75],
                                'Spouse':[65, 90, 65, 90, 90, 75, 90, 90, 55, 90, 75, 85, 80, 80, 85, 65, 90],
                                'Parents':[65, 90, 65, 90, 90, 65, 90, 90, 90, 90, 75, 85, 90, 90, 85, 65, 90]},
                  
                  'Travel':{'overseas frequently':[45, 75, 50, 90, 90, 90, 90, 90, 90, 90, 75, 85, 85, 90, 90, 90, 90],
                            'officialy':[45, 75, 50, 90, 90, 90, 90, 90, 90, 90, 75, 85, 85, 90, 90, 90, 90],
                            'Family holidays':[ 45, 75, 50, 90, 90, 90, 90, 90, 90, 90, 75, 85, 85, 90, 90, 90, 90]},
                  
                  'city':{'Metro':[55, 85, 55, 85, 85, 85, 90, 85, 85, 85, 85, 90, 75, 75, 85, 90, 90],
                            'Non-Metro':[75, 55, 85, 65, 85, 85, 90, 90, 90, 90, 90, 90, 90, 90, 65, 80, 50]}
                  }

    self.user_input = np.zeros(43)
    self.orignal_weight = np.zeros(17)
  
  # function to processes the user_input and change it according to ML model
  def check_age(self,customer_age):
    for age in customer_age:
      age = int(age)
      if age >=20 and age <= 30:
        self.user_input[0]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['age']['20-30']))
      
      elif age >=31 and age <= 35:
        self.user_input[1]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['age']['31-35']))
      
      elif age >35 and age <= 45:
        self.user_input[2]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['age']['35-45']))

      elif age >=45 and age < 55:
        self.user_input[3]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['age']['45-55']))

      elif age >=55 and age <= 64:
        self.user_input[4]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['age']['55-64']))

      
      elif age > 64:
        self.user_input[5]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['age']['65+senior citizen']))
        self.orignal_weight[8] =800

    

  def check_gender(self,customer_gender):
    for gender in customer_gender:
      if gender == 'F':
        self.user_input[6]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['gender']['Female']))
      elif gender == 'M':
        self.user_input[7]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['gender']['Male']))

  
  def check_Education(self,customer_Education):
    for Education in customer_Education:
      if Education == 'B':
        self.user_input[8]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Education_Qualifications']['Bachelors']))
      elif Education == 'MS':
        self.user_input[9]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Education_Qualifications']['Masters']))
      elif Education == 'MT':
        self.user_input[10]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Education_Qualifications']['Metriculate']))


  def chek_Income(self,customer_income):
    for income in customer_income:
      income = float(income)  
      if income >=0 and income <= 250000:
        self.user_input[11]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Income']['0-250000']))  
      elif income >1000000 :
        self.user_input[12]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Income']['1000000+']))   
      elif income >250000 and income <= 500000:
        self.user_input[13]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Income']['250000-500000']))
      elif income >500000 and income <= 1000000:
        self.user_input[14]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Income']['500000-1000000']))

   

  def check_loans(self,customer_loans):
    for loans in customer_loans:
      loans = loans.lower()
      if loans == 'home':
        self.user_input[15]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['loans']['Home']))


      elif loans == 'vehicle':
        self.user_input[16]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['loans']['Vehicle']))

 


  def chek_Financial(self,customer_financial_asset):
    for financial_asset in customer_financial_asset:
      financial_asset = float(financial_asset)
      
      if financial_asset >=0 and financial_asset <= 1000000:
        self.user_input[17]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['financial_asset']['0-1000000']))

      
      elif financial_asset >1000000 and financial_asset <=2000000 :
        self.user_input[18]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['financial_asset']['1000000-2000000']))

      
      elif financial_asset >10000000:
        self.user_input[19]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['financial_asset']['10000000+']))


      elif financial_asset >2000000 and financial_asset <= 5000000:
        self.user_input[20]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['financial_asset']['2000000-5000000']))


      elif financial_asset >5000000 and financial_asset <= 10000000:
        self.user_input[21]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['financial_asset']['5000000-10000000']))

    
  

  def check_Married(self,customer_married):
    for married in customer_married:
      if married == 'U':
        self.user_input[22]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Married']['No']))


      elif married == 'M':
        self.user_input[23]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Married']['yes']))


  def check_Occupation(self,customer_occupation):
    for occupation in customer_occupation:
      if occupation == 'SE':
        self.user_input[24]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Occupations']['Business Owner']))


      elif occupation == 'FL':
        self.user_input[25]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Occupations']['Freelancer']))


      elif occupation == 'U':
        self.user_input[26]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Occupations']['NotEmployed/Retired']))


      elif occupation == 'S':
        self.user_input[27]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Occupations']['work for a company']))

  

  def check_house(self,customer_house):
    for house in customer_house:
      if house == 'OH':
        self.user_input[28]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['House']['own a independent house']))


      elif house == 'OA':
        self.user_input[29]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['House']['own an apartment']))


      elif house == 'R':
        self.user_input[30]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['House']['rent']))

    
   

  def check_household(self,customer_household):
    for household in customer_household:
      if household == 'OHE':
        self.user_input[31]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Households']['own high value electronics']))
      elif household == 'OHJ':
        self.user_input[32]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Households']['own jewellery and high end watches']))



  def check_Vehicle(self,customer_Vehicle):
    for Vehicle in customer_Vehicle:
      if Vehicle == 'FW':
        self.user_input[33]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Vehicles']['four wheeler']))

      elif Vehicle == 'TW':
        self.user_input[34]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Vehicles']['two wheeler']))
    

  def check_Dependents(self,customer_dependent):
    for dependent in customer_dependent:
      if dependent == 'C':
        self.user_input[35]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Dependents']['Children']))


      elif dependent == 'P':
        self.user_input[36]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Dependents']['Parents']))


      elif dependent == 'S':
        self.user_input[37]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Dependents']['Spouse']))



  def check_Travel(self,customer_travel):
    for travel in customer_travel:
      if travel == 'FH':
        self.user_input[38]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Travel']['Family holidays']))


      elif travel == 'OFF':
        self.user_input[39]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Travel']['officialy']))


      elif travel == 'OF':
        self.user_input[40]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['Travel']['overseas frequently']))



  
  def check_city(self,customer_city):
    for city in customer_city:
      if city == 'M':
        self.user_input[41]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['city']['Metro']))

      elif city == 'NM':
        self.user_input[42]=1
        self.orignal_weight = list(map(add,self.orignal_weight, self.weight['city']['Non-Metro']))



 

  def input_process(self,feature_array):
    '''
      input : feature_array input of the user
      return: processed input of user in [1,0,0,1] and original weights of each insurance policy
    '''
    func_dict = {0:self.check_age, 1:self.check_gender, 2:self.check_Education, 3:self.chek_Income, 4:self.check_loans, 5:self.chek_Financial,
                        6:self.check_Married, 7:self.check_Occupation, 8:self.check_house, 9:self.check_household, 10:self.check_Vehicle, 11:self.check_Dependents,
                        12:self.check_Travel  ,13:self.check_city}
    for i,val in enumerate(feature_array):
      # if some value is missing we will skip
      if val =='':
        continue
      func_dict[i](val)
    return self.user_input,self.orignal_weight
  

  def get_orignal_weights(self, weight_arr):
    '''
    weight_arr: original weights of each insurance policy
    return sorted policy based on weights
    '''
    original_weights = {}
    weight_arr = [weight/17 for weight in weight_arr]
    for i,val in enumerate(self.insurance):
      original_weights[val] = weight_arr[i]

    return sorted(original_weights.items(), key = lambda x:x[1], reverse=True)

  

  def insurance_pred_dict(self,user_input,model,original_weights):
    '''
    user_input : processed user_input
    original_weights: original weights of each insurance policy
    return recommendation based on ml model and original weights
    '''
    pred = model.predict([user_input])
    insurance_dict={}
    for i in range(len(self.insurance)):
      insurance_dict[self.insurance[i]] = pred[0][i]
    original_weights_arr = self.get_orignal_weights(original_weights)

    for index in range(len(original_weights_arr)):
      key=original_weights_arr[index][0]
      val = original_weights_arr[index][1]
      insurance_dict[key] = insurance_dict[key]+val*insurance_dict[key]/100
    
    return insurance_dict


    



  

    
      
      
    



  

