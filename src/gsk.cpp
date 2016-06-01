/*
* Created By : Team Fluffy
* File Name : gsk.cpp
* Creation Date : Wed 17 Feb 2016 01:37:47 PM CST
* Last Modified : Tue 26 Apr 2016 04:30:21 PM PDT
* Purpose :
*
*/


#include "gsk.h"
BOOST_PYTHON_MODULE(gsk)
{
	using namespace boost::python;

	class_<Gsk>("Gsk")
		.def(init<std::string, std::string, std::string>())
		.def("printGsk", GenericGskPrint)
		;
	def("printGsk", GenericGskPrint);
}

//GSK constructors

Gsk::Gsk()
{
	Msg.hdr.msg_type.SetMsgType("GSK-REQ");
	Msg.pyld.type.SetPayloadType("REQUEST");
}
Gsk::Gsk(std::string msgtype, std::string groupkey = "",
         std::string keyid = "")
{
	Msg.hdr.msg_type.SetMsgType(msgtype);
	if (groupkey.size() < 16 || groupkey.size() > 32)
		groupkey = GenSymKey(128);
	if (keyid == "")
		keyid = Msg.pyld.kd.GetKeyId();
	
	if (msgtype == "GSK-REP" || msgtype == "GSK-DLVR"){
		Msg.pyld.type.SetPayloadType("RECEIPT");
		Msg.pyld.kd.keytype.SetKeyType("SYMGROUP");
		Msg.pyld.kd.symgrp.SetSymKey(GenSymKey(128));
		Msg.pyld.kd.symgrp.SetSymKey(groupkey);
		Msg.pyld.kd.SetKeyId(keyid);
	}
	else if(msgtype == "GSK-REQ" || msgtype == "GSK-FET"){
		Msg.pyld.type.SetPayloadType("REQUEST");
	}
}
/*
 * GenericGskPrint()
 * This function should take any GSK message
 * and perform the correct print.
 *
 */
std::string GenericGskPrint(Gsk &InputMsg)
{
	std::string json;
	std::string type = InputMsg.Msg.hdr.msg_type.GetMsgType();
    if (type == "GSK-REQ"){
	    json = GskReqJsonPrint(InputMsg);	    
    }
    else if (type == "GSK-REP"){
	    json = GskRepJsonPrint(InputMsg);
    }
    else if (type == "GSK-FET"){
	    json = GskFetJsonPrint(InputMsg);
    }
    else if (type == "GSK-DLVR"){
	    
	    json = GskDlvrJsonPrint(InputMsg);
    }
    else{
	    std::cout << "Error reading message type" <<std::endl;
	    std::cout << "Please specify a supported message type" << std::endl;
	    exit(-1);
    }

    return json;
}

std::string GskReqJsonPrint(Gsk &Msg)
{
	Json::Value root;   // 'root' will contain the root value after parsing.
	Json::StreamWriterBuilder wbuilder;
	std::string json;
	wbuilder["indentation"] = "\t";

	
	// You can also read into a particular sub-value.
	// Get the value of the member of root named 'encoding',
	// and return 'UTF-8' if there is no such member.
	// Get the value of the member of root named 'plug-ins'; return a 'null' value if
	// there is no such member.
	// Try other datatypes. Some are auto-convertible to others.
	// Since Json::Value has an implicit constructor for all value types, it is not
	// necessary to explicitly construct the Json::Value object.
	root["header"]["pvno"] = Msg.Msg.hdr.GetPvno();
	root["header"]["msgtyp"] = Msg.Msg.hdr.msg_type.GetMsgType();
	root["iss"] = Msg.Msg.to.GetRealm() + Msg.Msg.to.GetGroup() +
		Msg.Msg.to.GetName();
	root["sub"] = Msg.Msg.from.GetRealm() + Msg.Msg.from.GetGroup() +
		Msg.Msg.from.GetName();
	root["aud"] = Msg.Msg.target.GetRealm() + Msg.Msg.target.GetGroup() +
		Msg.Msg.target.GetName();
		root["to"]["name"] = Msg.Msg.to.GetName();
	root["to"]["realm"] = Msg.Msg.to.GetRealm();
	root["to"]["group"] = Msg.Msg.to.GetGroup();
	root["from"]["name"] = Msg.Msg.to.GetName();
	root["from"]["realm"] = Msg.Msg.from.GetRealm();
	root["from"]["group"] = Msg.Msg.from.GetGroup();
	root["target"]["name"] = Msg.Msg.target.GetName();
	root["target"]["realm"] = Msg.Msg.target.GetRealm();
	root["target"]["group"] = Msg.Msg.target.GetGroup();
	root["payload"]["type"] = Msg.Msg.pyld.type.GetPayloadType();
	root["payload"]["skdcopts"] = Msg.Msg.pyld.GetSkdcOptions();
	root["payload"]["keydata"]["keytyp"] = Msg.Msg.pyld.kd.keytype.GetKeyType();
	root["payload"]["keydata"]["kid"] = Msg.Msg.pyld.kd.GetKeyId();
	root["payload"]["keydata"]["algid"] = Msg.Msg.pyld.kd.GetAlgId();
	root["payload"]["pac"] = Msg.Msg.pyld.GetPac();
	root["payload"]["exp"] = Msg.Msg.pyld.GetEndtime();
	root["payload"]["iat"] = Msg.Msg.pyld.GetIssuetime();
	root["security"]["authtime"] = Msg.Msg.security.GetAuthTime();
	root["security"]["nonce"] = Msg.Msg.security.GetNonce();
	root["security"]["seqnum"] = Msg.Msg.security.GetSeqnum();
	root["security"]["khash"] = Msg.Msg.security.GetKhash();
	root["security"]["khashalg"] = Msg.Msg.security.GetKhashAlg();

	json = Json::writeString(wbuilder, root);
	
	return json;
}

std::string GskRepJsonPrint(Gsk &Msg)
{
	Json::Value root;   // 'root' will contain the root value after parsing.
	Json::StreamWriterBuilder wbuilder;
	std::string json;

		
	wbuilder["indentation"] = "\t";
	root["header"]["pvno"] = Msg.Msg.hdr.GetPvno();
	root["header"]["msgtyp"] = Msg.Msg.hdr.msg_type.GetMsgType();
	root["payload"]["iss"] = Msg.Msg.to.GetRealm() +
		Msg.Msg.to.GetGroup() + Msg.Msg.to.GetName();
	root["payload"]["sub"] = Msg.Msg.from.GetRealm() +
		Msg.Msg.from.GetGroup() + Msg.Msg.from.GetName();	
	root["payload"]["aud"] = Msg.Msg.target.GetRealm() +
		Msg.Msg.target.GetGroup() + Msg.Msg.target.GetName();
		root["to"]["name"] = Msg.Msg.to.GetName();
	root["to"]["realm"] = Msg.Msg.to.GetRealm();
	root["to"]["group"] = Msg.Msg.to.GetGroup();
	root["from"]["name"] = Msg.Msg.to.GetName();
	root["from"]["realm"] = Msg.Msg.from.GetRealm();
	root["from"]["group"] = Msg.Msg.from.GetGroup();
	root["target"]["name"] = Msg.Msg.target.GetName();
	root["target"]["realm"] = Msg.Msg.target.GetRealm();
	root["target"]["group"] = Msg.Msg.target.GetGroup();
	root["payload"]["type"] = Msg.Msg.pyld.type.GetPayloadType();
	root["payload"]["spi"] = Msg.Msg.pyld.GetSpi();
	root["payload"]["keydata"]["keytyp"] = Msg.Msg.pyld.kd.keytype.GetKeyType();
	root["payload"]["keydata"]["symgrp"]["k"] = Msg.Msg.pyld.kd.symgrp.GetSymKey();
	root["payload"]["keydata"]["kid"] = Msg.Msg.pyld.kd.GetKeyId();
	root["payload"]["keydata"]["algid"] = Msg.Msg.pyld.kd.GetAlgId();
	root["payload"]["pac"] = Msg.Msg.pyld.GetPac();
	root["payload"]["tpac"] = Msg.Msg.pyld.GetTpac();
	root["payload"]["skdcopts"] = Msg.Msg.pyld.GetSkdcOptions();
	root["payload"]["transited"] = Msg.Msg.pyld.GetTransited();
	root["payload"]["exp"] = Msg.Msg.pyld.GetEndtime();
	root["payload"]["iat"] = Msg.Msg.pyld.GetIssuetime();
	root["security"]["authtime"] = Msg.Msg.security.GetAuthTime();
	root["security"]["nonce"] = Msg.Msg.security.GetNonce();
	root["security"]["seqnum"] = Msg.Msg.security.GetSeqnum();
	root["security"]["khash"] = Msg.Msg.security.GetKhash();
	root["security"]["khashalg"] = Msg.Msg.security.GetKhashAlg();
		
	
	json = Json::writeString(wbuilder, root);
	return json;
}
std::string GskFetJsonPrint(Gsk &Msg)
{
	Json::Value root;   // 'root' will contain the root value after parsing.
	Json::StreamWriterBuilder wbuilder;
	std::string json;
	wbuilder["indentation"] = "\t";

	root["header"]["pvno"] = Msg.Msg.hdr.GetPvno();
	root["header"]["msgtyp"] = Msg.Msg.hdr.msg_type.GetMsgType();
		root["iss"] = Msg.Msg.to.GetRealm() + Msg.Msg.to.GetGroup() +
		Msg.Msg.to.GetName();
	root["sub"] = Msg.Msg.from.GetRealm() + Msg.Msg.from.GetGroup() +
		Msg.Msg.from.GetName();
	root["aud"] = Msg.Msg.target.GetRealm() + Msg.Msg.target.GetGroup() +
		Msg.Msg.target.GetName();
	root["to"]["name"] = Msg.Msg.to.GetName();
	root["to"]["realm"] = Msg.Msg.to.GetRealm();
	root["to"]["group"] = Msg.Msg.to.GetGroup();
	root["from"]["name"] = Msg.Msg.to.GetName();
	root["from"]["realm"] = Msg.Msg.from.GetRealm();
	root["from"]["group"] = Msg.Msg.from.GetGroup();
	root["target"]["name"] = Msg.Msg.target.GetName();
	root["target"]["realm"] = Msg.Msg.target.GetRealm();
	root["target"]["group"] = Msg.Msg.target.GetGroup();
	root["payload"]["type"] = Msg.Msg.pyld.type.GetPayloadType();
	root["payload"]["skdcopts"] = Msg.Msg.pyld.GetSkdcOptions();
	root["payload"]["keydata"]["kid"] = Msg.Msg.pyld.kd.GetKeyId();
	root["payload"]["exp"] = Msg.Msg.pyld.GetEndtime();
	root["payload"]["iat"] = Msg.Msg.pyld.GetIssuetime();
	root["security"]["authtime"] = Msg.Msg.security.GetAuthTime();
	root["security"]["nonce"] = Msg.Msg.security.GetNonce();
	root["security"]["seqnum"] = Msg.Msg.security.GetSeqnum();
	root["security"]["khash"] = Msg.Msg.security.GetKhash();
	root["security"]["khashalg"] = Msg.Msg.security.GetKhashAlg();
	
	json = Json::writeString(wbuilder, root);
	return json;
}

std::string GskDlvrJsonPrint(Gsk &Msg)
{
	Json::Value root;   // 'root' will contain the root value after parsing.
	Json::StreamWriterBuilder wbuilder;
	std::string json;
	wbuilder["indentation"] = "\t";

  	root["header"]["pvno"] = Msg.Msg.hdr.GetPvno();
	root["header"]["msgtyp"] = Msg.Msg.hdr.msg_type.GetMsgType();
	root["payload"]["iss"] = Msg.Msg.to.GetRealm() +
		Msg.Msg.to.GetGroup() + Msg.Msg.to.GetName();
	root["payload"]["sub"] = Msg.Msg.from.GetRealm() +
		Msg.Msg.from.GetGroup() + Msg.Msg.from.GetName();
	root["payload"]["aud"] = Msg.Msg.target.GetRealm() +
		Msg.Msg.target.GetGroup() + Msg.Msg.target.GetName();
	root["to"]["name"] = Msg.Msg.to.GetName();
	root["to"]["realm"] = Msg.Msg.to.GetRealm();
	root["to"]["group"] = Msg.Msg.to.GetGroup();
	root["from"]["name"] = Msg.Msg.to.GetName();
	root["from"]["realm"] = Msg.Msg.from.GetRealm();
	root["from"]["group"] = Msg.Msg.from.GetGroup();
	root["target"]["name"] = Msg.Msg.target.GetName();
	root["target"]["realm"] = Msg.Msg.target.GetRealm();
	root["target"]["group"] = Msg.Msg.target.GetGroup();
	root["payload"]["type"] = Msg.Msg.pyld.type.GetPayloadType();
	root["payload"]["keydata"]["keytyp"] = Msg.Msg.pyld.kd.keytype.GetKeyType();
	root["payload"]["keydata"]["symgrp"]["k"] = Msg.Msg.pyld.kd.symgrp.GetSymKey();
	root["payload"]["keydata"]["kid"] = Msg.Msg.pyld.kd.GetKeyId();
	root["payload"]["keydata"]["algid"] = Msg.Msg.pyld.kd.GetAlgId();
	root["payload"]["pac"] = Msg.Msg.pyld.GetPac();
	root["payload"]["tpac"] = Msg.Msg.pyld.GetTpac();
	root["payload"]["skdcopts"] = Msg.Msg.pyld.GetSkdcOptions();
	root["payload"]["transited"] = Msg.Msg.pyld.GetTransited();
	root["payload"]["exp"] = Msg.Msg.pyld.GetEndtime();
	root["payload"]["iat"] = Msg.Msg.pyld.GetIssuetime();
	root["security"]["authtime"] = Msg.Msg.security.GetAuthTime();
	root["security"]["nonce"] = Msg.Msg.security.GetNonce();
	root["security"]["seqnum"] = Msg.Msg.security.GetSeqnum();
	root["security"]["khash"] = Msg.Msg.security.GetKhash();
	root["security"]["khashalg"] = Msg.Msg.security.GetKhashAlg();
	// If you like the defaults, you can insert directly into a stream.
		// Of course, you can write to `std::ostringstream` if you prefer.
	// If desired, remember to add a linefeed and flush.
	
	json = Json::writeString(wbuilder, root);
  return json;

}
