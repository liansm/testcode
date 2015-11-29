#compare the goods price

import urllib2 
#from lxml import etree
#import xml.dom.minidom
#import xml.etree.ElementTree as ET

def get_local_info(goods_id):
	user_agent = 'Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_6_4; en-US) AppleWebKit/534.3 (KHTML, like Gecko) Chrome/6.0.472.63 Safari/534.3'
	headers = { 'User-Agent' : user_agent }
	goods_url = 'http://api.baobeigezi.com/item/detail/product_suit_info/' + str(goods_id)
	req = urllib2.Request(goods_url, None, headers)
	response = urllib2.urlopen(req)
	page = response.read()
	page_lines = page.splitlines()
	goods_price = '' 
	goods_url = ''
	line_num = 0
	for line in page_lines:
		line_num = line_num+1
		#local price
		if line_num == 9 and line.find("market_price") != -1:
			goods_price =line[28:-7] 
		#foreign website address
		elif line_num == 27 and line.find("addanniu") != -1:
			a,b,c=line.partition('href=')
			d,e,f=c.partition('target=')
			goods_url = d[1:-2]
			break
		#error check
		elif line_num > 27:
			print 'Error, goods info not found, goods_id=', goods_id
			break
	return goods_price,goods_url

def get_remote_price(goods_url):
	if goods_url.find('chemistwarehouse') != -1:
		return get_remote_pricei_from_chemistwarehouse(goods_url)	


def get_remote_pricei_from_chemistwarehouse(goods_url):
	a,b,c=goods_url.partition('&pname')
	d,e,f=a.partition('id=')
	goods_id = f
	user_agent = 'Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_6_4; en-US) AppleWebKit/534.3 (KHTML, like Gecko) Chrome/6.0.472.63 Safari/534.3'
	headers = { 'User-Agent' : user_agent }
	req = urllib2.Request(goods_url, None, headers)
	response = urllib2.urlopen(req)
	page = response.read()
	page_lines = page.splitlines()
	goods_price = '' 
	line_num = 0
	for line in page_lines:
		line_num = line_num+1
		if line.find("class=\"ProductPage_NormalPrice") != -1:
			a,b,c=line.partition('itemprop=\"price\"')
			goods_price = c[1:-6]
			break
	return goods_id, goods_price


price_local,url = get_local_info(16153)
print price_local
print url
remote_goods_id, price_remote = get_remote_price(url)
print remote_goods_id
print price_remote

