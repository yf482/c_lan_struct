

int main(){
//获取待处理数据集  List结构
dataList = getDataList();
//过滤dataList数据
filterList = handleDataList(dataList);
//对filterList进行排序
filterList = sortFilterList(filterList);
//打印filterList
printFilterList(filterList);
return 0；
}

//过滤dataList数据
filterList handleDataList(dataList){
	//初始化filterMap  List结构
	filterList = new filterList();
	//遍历处理待处理数据集
	for(d_entity : dataList)
	{	//待处理实体名称
		d_name = d_entity.getName();
		//待处理实体属性名
		d_attr = d_entity.getAttr();
		//待处理实体属性值
		d_attrVal = d_entity.getAttrVal();
		//获取已经处理数据集
		f_entiryAll = filterList.getAll();
		//相似标识 true相似  false非相似  默认为false
		bool similarFlag = false;
		//遍历查找已处理数据集
		for(f_entity : f_entityAll)
		{
			//获取已处理实体名称
			f_name = f_entity.getName();
			//获取已处理实体属性名
			f_attr = f_entity.getAttr();
			//获取已处理实体属性值
			f_attrVal = f_entity.getAttrVal();
			//如果待处理实体名称、属性名、属性值 和 已处理实体相似度名称、属性名、属性值都大于等于0.7，则相似
			if(synonyms.compare(d_name, f_name) >= 0.7 
				&& synonyms.compare(d_attr, f_attr) >= 0.7 
				&& synonyms.compare(d_attrVal, f_attrVal) >= 0.7 )
			{				  	
				//置相似标识为true
				similarFlag = true;
			}else{
				//不相似继续匹配
				continue
			}	
		}
		//相识度== false 
		if(similarFlag == false){
			//把该待处理实体添加到已处理数据集中
			filterList.add(d_entity);
		}
	 }
	 return filterList;
	
}
//对filterList进行排序 按对应中文字符a-z大小排序
filterList sortFilterList(filterList){
	//返回排序后的filterList
	return filterList;
}
 
//打印filterList，遍历打印
void printFilterList(filterList){
	for(entity : filterList){
		print(entity);
	}
}
