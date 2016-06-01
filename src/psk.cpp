/*
 * Created By : Team Fluffy
 * File Name : psk.cpp
 * Creation Date : Wed 3 Feb 2016 15:01:43 AM PST
 * Last Modified : 
 * Purpose : test program for the psk classes.
 */
#include <psk.h>
/*
int main(int argc, const char *argv[])
{
	PskReq m1;
	PskRep m2;
	PskEstb m3;
	PskAck m4;

	//printing data
	std::cout << m1.ReqMsg.hdr.GetPvno() << std::endl;
	std::cout << m1.ReqMsg.hdr.msg_type.GetMsgType() << std::endl;
	std::cout << m1.ReqMsg.to.GetRealm() << std::endl;
	std::cout << m1.ReqMsg.to.GetName() << std::endl;
	std::cout << m1.ReqMsg.to.GetGroup() << std::endl;
	std::cout << m1.ReqMsg.from.GetRealm() << std::endl;
	std::cout << m1.ReqMsg.from.GetName() << std::endl;
	std::cout << m1.ReqMsg.from.GetGroup() << std::endl;
	std::cout << m1.ReqMsg.target.GetRealm() << std::endl;
	std::cout << m1.ReqMsg.target.GetName() << std::endl;
	std::cout << m1.ReqMsg.target.GetGroup() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_skdc_optionsr() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_issuetime() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_endtime() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_transmited() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_pac() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_tpac() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_x5u() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_x5c() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_x5t() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_x5t256() << std::endl;
	//std::cout << m1.reqMsg.pyld.get_pk10() << std::endl;
	// what about kd.keytype
	std::cout << m1.ReqMsg.security.GetAuthTime() << std::endl;
	std::cout << m1.ReqMsg.security.GetNonce() << std::endl;
	std::cout << m1.ReqMsg.security.GetSeqnum() << std::endl;
	std::cout << m1.ReqMsg.security.GetKhashAlg() << std::endl;
	std::cout << m1.ReqMsg.security.GetKhash() << std::endl;
	//std::cout << m1.reqMsg.to.GetName() << std::endl;
	
	//printing data
	std::cout << m2.RepMsg.hdr.GetPvno() << std::endl;
	std::cout << m2.RepMsg.security.GetNonce() << std::endl;
	std::cout << m2.RepMsg.security.GetSeqnum() << std::endl;
	//std::cout << m2.repMsg.to.GetName() << std::endl;

	//printing data
	std::cout << m3.EstbMsg.hdr.GetPvno() << std::endl;
	std::cout << m3.EstbMsg.hdr.msg_type.GetMsgType() << std::endl;
	std::cout << m3.EstbMsg.to.GetRealm() << std::endl;
	std::cout << m3.EstbMsg.to.GetName() << std::endl;
	std::cout << m3.EstbMsg.to.GetGroup() << std::endl;
	std::cout << m3.EstbMsg.from.GetRealm() << std::endl;
	std::cout << m3.EstbMsg.from.GetName() << std::endl;
	std::cout << m3.EstbMsg.from.GetGroup() << std::endl;
	std::cout << m3.EstbMsg.target.GetRealm() << std::endl;
	std::cout << m3.EstbMsg.target.GetName() << std::endl;
	std::cout << m3.EstbMsg.target.GetGroup() << std::endl;
//what about msg.wypyld?
	std::cout << m3.EstbMsg.security.GetAuthTime() << std::endl;
	std::cout << m3.EstbMsg.security.GetNonce() << std::endl;
	std::cout << m3.EstbMsg.security.GetSeqnum() << std::endl;
	std::cout << m3.EstbMsg.security.GetKhashAlg() << std::endl;
	std::cout << m3.EstbMsg.security.GetKhash() << std::endl;
	//std::cout << m3.EstbMsg.to.GetName() << std::endl;


	//printing data
	std::cout << m4.AckMsg.hdr.GetPvno() << std::endl;
	std::cout << m4.AckMsg.hdr.msg_type.GetMsgType() << std::endl;
	std::cout << m4.AckMsg.to.GetRealm() << std::endl;
	std::cout << m4.AckMsg.to.GetName() << std::endl;
	std::cout << m4.AckMsg.to.GetGroup() << std::endl;
	std::cout << m4.AckMsg.from.GetRealm() << std::endl;
	std::cout << m4.AckMsg.from.GetName() << std::endl;
	std::cout << m4.AckMsg.from.GetGroup() << std::endl;
	std::cout << m4.AckMsg.target.GetRealm() << std::endl;
	std::cout << m4.AckMsg.target.GetName() << std::endl;
	std::cout << m4.AckMsg.target.GetGroup() << std::endl;
	std::cout << m4.AckMsg.security.GetAuthTime() << std::endl;
	std::cout << m4.AckMsg.security.GetNonce() << std::endl;
	std::cout << m4.AckMsg.security.GetSeqnum() << std::endl;
	std::cout << m4.AckMsg.security.GetKhashAlg() << std::endl;
	std::cout << m4.AckMsg.security.GetKhash() << std::endl;
	//std::cout << m4.AckMsg.to.GetName() << std::endl;
}


*/
